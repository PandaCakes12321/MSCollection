package com.teff.puzzles.ratpoker;

import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;
import android.graphics.RectF;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/** Loads a sprites.txt / PNG pair and draws individual frames. */
final class SpriteSheet {

    static final class Frame {
        final int x, y, w, h, hx, hy;
        Frame(int x, int y, int w, int h, int hx, int hy) {
            this.x = x; this.y = y; this.w = w; this.h = h;
            this.hx = hx; this.hy = hy;
        }
    }

    private final Map<String, Bitmap> strips = new HashMap<>();
    private final Map<String, List<Frame>> frames = new HashMap<>();

    void load(AssetManager am, String id) {
        try {
            InputStream is = am.open("ratpoker/spr/sprites.txt");
            BufferedReader br = new BufferedReader(new InputStreamReader(is));
            String line;
            while ((line = br.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) continue;
                String[] p = line.split("\\s+");
                if (p.length < 8) continue;
                String name = p[0];
                int x = Integer.parseInt(p[2]), y = Integer.parseInt(p[3]);
                int w = Integer.parseInt(p[4]), h = Integer.parseInt(p[5]);
                int hx = Integer.parseInt(p[6]), hy = Integer.parseInt(p[7]);
                frames.computeIfAbsent(name, k -> new ArrayList<>()).add(new Frame(x, y, w, h, hx, hy));
                // load strip if not loaded
                if (!strips.containsKey(name)) {
                    try {
                        InputStream img = am.open("ratpoker/spr/" + name + ".png");
                        strips.put(name, BitmapFactory.decodeStream(img));
                        img.close();
                    } catch (Exception e) { /* missing sprite */ }
                }
            }
            br.close();
        } catch (Exception e) { /* no sprites.txt */ }
    }

    int frameCount(String name) {
        List<Frame> fl = frames.get(name);
        return fl == null ? 0 : fl.size();
    }

    Frame frame(String name, int idx) {
        List<Frame> fl = frames.get(name);
        if (fl == null || fl.isEmpty()) return null;
        return fl.get(idx % fl.size());
    }

    /** Draw sprite centered on (cx, cy) in logical coordinates scaled by s. */
    void draw(Canvas c, Paint p, String name, int frameIdx, float cx, float cy, float s) {
        Bitmap bmp = strips.get(name);
        if (bmp == null) return;
        Frame f = frame(name, frameIdx);
        if (f == null) return;
        Rect src = new Rect(f.x, f.y, f.x + f.w, f.y + f.h);
        float dx = (cx - f.hx) * s;
        float dy = (cy - f.hy) * s;
        RectF dst = new RectF(dx, dy, dx + f.w * s, dy + f.h * s);
        c.drawBitmap(bmp, src, dst, p);
    }
}
