package com.teff.puzzles;

import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.RectF;
import android.os.Bundle;
import android.text.TextPaint;
import android.view.MotionEvent;
import android.view.View;

import com.teff.puzzles.common.BaseGameActivity;
import com.teff.puzzles.common.Games;

import java.io.IOException;
import java.io.InputStream;

/** The game menu: 10 big tiles (5 x 2), each the game's original About picture plus its name. */
public class MenuActivity extends BaseGameActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(new MenuView(this));
    }

    /** The menu is the home screen, so back here leaves the app. */
    @Override
    public void exitToMenu() {
        finish();
    }

    private final class MenuView extends View {
        private static final int W = 650, H = 400, COLS = 5, ROWS = 2;
        private static final float TILE_W = 118, TILE_H = 160, GAP_X = 10, TOP = 60;

        private final Bitmap[] icons = new Bitmap[Games.ALL.length];
        private final Paint paint = new Paint(Paint.FILTER_BITMAP_FLAG | Paint.ANTI_ALIAS_FLAG);
        private final Paint fill = new Paint(Paint.ANTI_ALIAS_FLAG);
        private final TextPaint text = new TextPaint(Paint.ANTI_ALIAS_FLAG);
        private float scale = 1f, offsetX, offsetY;
        private int pressed = -1;

        MenuView(Context context) {
            super(context);
            for (int i = 0; i < icons.length; i++) {
                try (InputStream in = context.getAssets().open("icons/" + Games.ALL[i].id + ".png")) {
                    icons[i] = BitmapFactory.decodeStream(in);
                } catch (IOException e) {
                    icons[i] = null;
                }
            }
            text.setColor(Color.WHITE);
        }

        @Override
        protected void onSizeChanged(int w, int h, int oldw, int oldh) {
            scale = Math.min(w / (float) W, h / (float) H);
            offsetX = (w - W * scale) / 2f;
            offsetY = (h - H * scale) / 2f;
        }

        private RectF tile(int i) {
            float left = (W - COLS * TILE_W - (COLS - 1) * GAP_X) / 2f + (i % COLS) * (TILE_W + GAP_X);
            float top = TOP + (i / COLS) * (TILE_H + 12);
            return new RectF(left, top, left + TILE_W, top + TILE_H);
        }

        @Override
        protected void onDraw(Canvas canvas) {
            canvas.drawColor(0xFF163016);
            canvas.save();
            canvas.translate(offsetX, offsetY);
            canvas.scale(scale, scale);

            text.setTextSize(30);
            text.setFakeBoldText(true);
            String title = "Puzzle Collection";
            canvas.drawText(title, (W - text.measureText(title)) / 2f, 42, text);
            text.setFakeBoldText(false);

            for (int i = 0; i < Games.ALL.length; i++) {
                RectF r = tile(i);
                fill.setColor(i == pressed ? 0xFF4F8F3A : 0xFF2F6B24);
                canvas.drawRoundRect(r, 10, 10, fill);
                if (icons[i] != null) {
                    float size = 98;
                    float x = r.centerX() - size / 2f, y = r.top + 10;
                    canvas.drawBitmap(icons[i], null, new RectF(x, y, x + size, y + size), paint);
                }
                drawCentered(canvas, Games.ALL[i].title, r.centerX(), r.top + 132, r.width() - 8);
            }
            canvas.restore();
        }

        /** One or two lines, shrunk to fit the tile. */
        private void drawCentered(Canvas canvas, String label, float cx, float y, float maxWidth) {
            text.setTextSize(15);
            String[] lines = text.measureText(label) <= maxWidth || !label.contains(" ")
                    ? new String[] {label}
                    : label.split(" ", 2);
            for (int i = 0; i < lines.length; i++) {
                float w = text.measureText(lines[i]);
                canvas.drawText(lines[i], cx - w / 2f, y + i * 17 - (lines.length - 1) * 8, text);
            }
        }

        private int tileAt(MotionEvent e) {
            float x = (e.getX() - offsetX) / scale, y = (e.getY() - offsetY) / scale;
            for (int i = 0; i < Games.ALL.length; i++) {
                if (tile(i).contains(x, y)) {
                    return i;
                }
            }
            return -1;
        }

        @Override
        public boolean onTouchEvent(MotionEvent e) {
            switch (e.getActionMasked()) {
                case MotionEvent.ACTION_DOWN:
                    pressed = tileAt(e);
                    invalidate();
                    return true;
                case MotionEvent.ACTION_UP:
                    int hit = tileAt(e);
                    if (hit >= 0 && hit == pressed) {
                        performClick();
                        startActivity(new Intent(MenuActivity.this, Games.ALL[hit].activity));
                    }
                    pressed = -1;
                    invalidate();
                    return true;
                case MotionEvent.ACTION_CANCEL:
                    pressed = -1;
                    invalidate();
                    return true;
                default:
                    return true;
            }
        }

        @Override
        public boolean performClick() {
            return super.performClick();
        }
    }
}
