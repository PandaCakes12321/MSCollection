// Ghidra headless post-script: writes every function's decompiled C into one file.
// Usage (as -postScript): ExportDecompiled.java <out-file>
import java.io.PrintWriter;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;

public class ExportDecompiled extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String out = getScriptArgs()[0];
        DecompInterface dec = new DecompInterface();
        dec.openProgram(currentProgram);
        int count = 0;
        try (PrintWriter w = new PrintWriter(out, "UTF-8")) {
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                if (f.isThunk() || f.isExternal()) {
                    continue;
                }
                DecompileResults r = dec.decompileFunction(f, 60, monitor);
                w.println("// ==== " + f.getName() + " @ " + f.getEntryPoint());
                w.println(r.decompileCompleted() ? r.getDecompiledFunction().getC() : "// decompile failed");
                count++;
            }
        }
        dec.dispose();
        println("Exported " + count + " functions to " + out);
    }
}
