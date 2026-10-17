package com.teff.puzzles;

import android.app.Application;
import android.os.Handler;
import android.os.Looper;
import android.widget.Toast;

import java.io.PrintWriter;
import java.io.StringWriter;

/** Global crash handler: shows the exception as a long Toast before the process dies. */
public final class PuzzleApp extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
        final Thread.UncaughtExceptionHandler defaultHandler =
                Thread.getDefaultUncaughtExceptionHandler();
        Thread.setDefaultUncaughtExceptionHandler((t, e) -> {
            StringWriter sw = new StringWriter();
            e.printStackTrace(new PrintWriter(sw));
            String msg = e.getClass().getSimpleName() + ": " + e.getMessage()
                    + "\n\n" + sw.toString();
            try {
                new Handler(Looper.getMainLooper()).post(() ->
                        Toast.makeText(this, msg, Toast.LENGTH_LONG).show());
                Thread.sleep(4000);
            } catch (InterruptedException ignored) {}
            if (defaultHandler != null) defaultHandler.uncaughtException(t, e);
        });
    }
}
