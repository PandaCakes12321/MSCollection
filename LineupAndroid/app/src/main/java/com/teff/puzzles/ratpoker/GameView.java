package com.teff.puzzles.ratpoker;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.RectF;
import android.os.Handler;
import android.os.Looper;
import android.view.MotionEvent;
import android.view.View;

import com.teff.puzzles.common.ControlPad;
import com.teff.puzzles.common.GameAudio;

import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;

final class GameView extends View implements Game.Listener, ControlPad.Listener {

    // Logical canvas size (matches background PNG)
    private static final int W = 620, H = 400;
    private static final int KEY = 60;   // control pad key size in logical coords

    // Belt layout (logical coords)
    private static final int BELT_X0 = 30,  BELT_X1 = 530;
    private static final int BELT_Y  = 295;  // rat centre on belt
    private static final int PLAT_X0 = 30,  PLAT_Y = 360;
    private static final int ARM_TOP  = 220;
    private static final int COMB_X   = 402, COMB_Y0 = 5;

    final Game game;
    private final GameAudio audio;
    private final ControlPad pad;
    private final SpriteSheet sprites = new SpriteSheet();
    private final Map<String, Bitmap> images = new HashMap<>();

    private float scale = 1f, offX, offY;
    private final Paint paint = new Paint(Paint.ANTI_ALIAS_FLAG | Paint.FILTER_BITMAP_FLAG);
    private final Paint fill  = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint txt   = new Paint(Paint.ANTI_ALIAS_FLAG);

    private final Handler handler = new Handler(Looper.getMainLooper());
    private boolean running;
    private final Runnable loop = new Runnable() {
        public void run() {
            if (!running) return;
            game.tick(25);
            invalidate();
            handler.postDelayed(loop, 25);
        }
    };

    GameView(RatpokerActivity host) {
        super(host);
        game = new Game();
        game.listener = this;
        audio = new GameAudio(host, "ratpoker");
        sprites.load(host.getAssets(), "ratpoker");
        loadImages(host);

        txt.setColor(Color.WHITE);
        txt.setTextSize(14);
        txt.setShadowLayer(1, 1, 1, Color.BLACK);

        // Control pad: arrow cluster bottom-left, SPACE+TAB bottom-right of arrows
        pad = new ControlPad(this);
        pad.addArrows(10, H - 3 * KEY - 4, KEY, false);          // left + right arrows
        pad.add(ControlPad.SPACE, 10 + 3 * KEY + 6, H - 2 * KEY - 4, KEY * 2, KEY, "SPC");
        pad.add(ControlPad.TAB,   10 + 3 * KEY + 6, H - KEY,          KEY * 2, KEY, "TAB");

        setOnTouchListener((v, e) -> {
            pad.onTouch(e, offX, offY, scale);
            return true;
        });
    }

    private void loadImages(Context ctx) {
        String[] names = {
            "BACKGROUND00","BACKGROUND01","BACKGROUND02","BACKGROUND03",
            "BACKGROUND04","BACKGROUND05","BACKGROUND06",
            "COMB00","COMB01","COMB02","COMB03","COMB04","COMB05","COMB06",
            "COMB07","COMB08","COMB10","COMB11","COMB12","COMB13","COMB14",
            "COMB15","COMB16","COMB17","COMB18",
            "LEVSCORE","PAUSEBMP","GAMEOVERBMP","TITLEBMP"
        };
        for (String n : names) {
            try {
                InputStream is = ctx.getAssets().open("ratpoker/img/" + n + ".png");
                images.put(n, BitmapFactory.decodeStream(is));
                is.close();
            } catch (IOException ignored) {}
        }
    }

    void onHostResume() { running = true; handler.post(loop); }
    void onHostPause()  { running = false; handler.removeCallbacks(loop); pad.releaseAll(); }
    void release()      { running = false; handler.removeCallbacks(loop); audio.release(); }

    @Override
    protected void onSizeChanged(int w, int h, int ow, int oh) {
        float sx = (float) w / W, sy = (float) h / H;
        scale = Math.min(sx, sy);
        offX = (w - W * scale) / 2f;
        offY = (h - H * scale) / 2f;
    }

    @Override
    protected void onDraw(Canvas canvas) {
        canvas.drawColor(Color.BLACK);
        canvas.save();
        canvas.translate(offX, offY);
        canvas.scale(scale, scale);

        switch (game.state) {
            case TITLE:      drawTitle(canvas);  break;
            case PLAYING:
            case PAUSED:     drawGame(canvas);   break;
            case OVER:       drawGame(canvas);   drawOverlay(canvas); break;
            case LEVEL_DONE: drawGame(canvas);   drawLevelDone(canvas); break;
        }

        pad.draw(canvas);
        canvas.restore();
    }

    // ---- screens ------------------------------------------------------------
    private void drawTitle(Canvas c) {
        Bitmap bg = images.get("TITLEBMP");
        if (bg != null) c.drawBitmap(bg, null, new RectF(0, 0, W, H), paint);
        else { fill.setColor(Color.DKGRAY); c.drawRect(0, 0, W, H, fill); }
        fill.setColor(0x88000000); c.drawRect(0, 0, W, H, fill);
        txt.setTextSize(26); txt.setTextAlign(Paint.Align.CENTER);
        c.drawText("RAT POKER", W / 2f, H / 2f - 24, txt);
        txt.setTextSize(16);
        c.drawText("Tap SPC to start", W / 2f, H / 2f + 16, txt);
        txt.setTextAlign(Paint.Align.LEFT);
    }

    private void drawGame(Canvas c) {
        Bitmap bg = images.get(bgKey());
        if (bg != null) c.drawBitmap(bg, null, new RectF(0, 0, W, H), paint);
        drawArms(c);
        drawBelt(c);
        drawPlatform(c);
        drawRightPanel(c);
        if (game.state == Game.State.PAUSED) {
            Bitmap pb = images.get("PAUSEBMP");
            if (pb != null) drawCentered(c, pb, W / 2, H / 2);
        }
    }

    private void drawOverlay(Canvas c) {
        Bitmap bmp = images.get("GAMEOVERBMP");
        if (bmp != null) { drawCentered(c, bmp, W / 2, H / 2); return; }
        fill.setColor(0xCC000000);
        c.drawRect(80, 100, 540, 290, fill);
        txt.setTextSize(30); txt.setTextAlign(Paint.Align.CENTER);
        c.drawText("GAME OVER", W / 2f, 175, txt);
        txt.setTextSize(18);
        c.drawText("Score: " + game.score, W / 2f, 225, txt);
        txt.setTextAlign(Paint.Align.LEFT);
    }

    private void drawLevelDone(Canvas c) {
        Bitmap ls = images.get("LEVSCORE");
        if (ls != null) drawCentered(c, ls, W / 2, H / 2);
        fill.setColor(0xAA000000);
        c.drawRect(180, H / 2f - 24, 440, H / 2f + 24, fill);
        txt.setTextSize(20); txt.setTextAlign(Paint.Align.CENTER);
        c.drawText("Level " + game.level + " complete!", W / 2f, H / 2f + 8, txt);
        txt.setTextAlign(Paint.Align.LEFT);
    }

    // ---- belt ---------------------------------------------------------------
    private void drawBelt(Canvas c) {
        float slotW = (float)(BELT_X1 - BELT_X0) / Game.MAX_BELT;
        for (Game.Rat r : game.belt) {
            float cx = BELT_X0 + (r.beltPos + 0.5f) * slotW;
            sprites.draw(c, paint, ratSprite(r.color, r.modifier), r.frame, cx, BELT_Y, 1f);
        }
    }

    // ---- arms ---------------------------------------------------------------
    private void drawArms(Canvas c) {
        float slotW = (float)(BELT_X1 - BELT_X0) / Game.MAX_BELT;
        fill.setStrokeWidth(3f);
        fill.setStyle(Paint.Style.STROKE);
        for (int i = 0; i < game.numArms; i++) {
            Game.Arm arm = game.arms[i];
            float cx = BELT_X0 + (arm.beltPos + 0.5f) * slotW;
            boolean active = (i == game.activeArm);
            fill.setColor(active ? Color.YELLOW : Color.LTGRAY);
            c.drawLine(cx, ARM_TOP, cx, BELT_Y - 22, fill);   // rod
            fill.setStyle(Paint.Style.FILL);
            c.drawCircle(cx, ARM_TOP + 8, 6, fill);           // pivot dot
            fill.setStyle(Paint.Style.STROKE);
            // trapped rats hanging from arm
            for (int s = 0; s < arm.numSlots; s++) {
                if (arm.trapped[s] == Game.NONE) continue;
                float ty = ARM_TOP + 30 + s * 32f;
                if (active && s == game.activeSlot) {
                    fill.setStyle(Paint.Style.FILL);
                    fill.setColor(0x44FFFFFF);
                    c.drawCircle(cx, ty, 15, fill);
                    fill.setStyle(Paint.Style.STROKE);
                    fill.setColor(Color.YELLOW);
                }
                sprites.draw(c, paint, ratSprite(arm.trapped[s], arm.trapMod[s]),
                        game.globalAnim, cx, ty, 1f);
            }
            fill.setStyle(Paint.Style.STROKE);
        }
    }

    // ---- platform -----------------------------------------------------------
    private void drawPlatform(Canvas c) {
        float slotW = (float)(COMB_X - PLAT_X0 - 10) / Game.MAX_PLAT;
        for (int i = 0; i < game.platCount; i++) {
            int col = game.platform[i];
            if (col == Game.NONE) continue;
            float cx = PLAT_X0 + (i + 0.5f) * slotW;
            sprites.draw(c, paint, ratSprite(col, 0), game.globalAnim % 4, cx, PLAT_Y, 1f);
        }
    }

    // ---- right panel --------------------------------------------------------
    private void drawRightPanel(Canvas c) {
        int[] combIds = {0,1,2,3,4,5,6,7,8,10,11,12,13,14,15,16,17,18};
        int shown = 0;
        for (int id : combIds) {
            String key = id < 10 ? "COMB0" + id : "COMB" + id;
            Bitmap bmp = images.get(key);
            if (bmp == null) continue;
            float y = COMB_Y0 + shown * 20f;
            if (y + 20 > H - 55) break;
            c.drawBitmap(bmp, null, new RectF(COMB_X, y, COMB_X + 215f, y + 18f), paint);
            shown++;
        }
        txt.setTextSize(13); txt.setTextAlign(Paint.Align.LEFT);
        c.drawText("Score:   " + game.score,              COMB_X + 2, H - 42f, txt);
        c.drawText("Level:   " + game.level + "/" + game.levelCount(), COMB_X + 2, H - 26f, txt);
        c.drawText("Rescued: " + game.rescued + "/" + game.rescueTarget, COMB_X + 2, H - 10f, txt);
    }

    // ---- helpers ------------------------------------------------------------
    private void drawCentered(Canvas c, Bitmap bmp, int cx, int cy) {
        c.drawBitmap(bmp, cx - bmp.getWidth() / 2f, cy - bmp.getHeight() / 2f, paint);
    }

    private String bgKey() {
        return "BACKGROUND0" + Math.min((game.level - 1) / 3, 6);
    }

    private String ratSprite(int col, int mod) {
        String base = "RAT_" + Game.COL_NAME[col];
        if (mod > 0) return base + "_P";
        if (mod < 0) return base + "_M";
        return base;
    }

    // ---- ControlPad.Listener -----------------------------------------------
    @Override
    public void keyDown(int code) {
        switch (code) {
            case ControlPad.SPACE: game.pressSpace(); break;
            case ControlPad.TAB:   game.pressTab();   break;
            case ControlPad.LEFT:  game.pressLeft();  break;
            case ControlPad.RIGHT: game.pressRight(); break;
        }
        if (game.state == Game.State.LEVEL_DONE) {
            handler.postDelayed(() -> { game.level++; game.startLevel(); }, 2500);
        }
    }

    @Override public void keyUp(int code) {}

    // ---- Game.Listener ------------------------------------------------------
    @Override public void sound(String name)  { audio.play(name); }
    @Override public void tip(int level)      {}
    @Override public void gameOver(int score) { invalidate(); }
}
