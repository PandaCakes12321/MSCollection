package com.teff.puzzles.common;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.RectF;
import android.text.TextPaint;
import android.view.KeyEvent;
import android.view.MotionEvent;

import java.util.ArrayList;
import java.util.List;

/**
 * Shared on-screen keyboard for the games that used arrow keys / Space / Tab.
 *
 * A game creates one, adds the keys it needs at positions in its own logical layout
 * (the same coordinate space it draws in), then:
 *   - calls {@link #draw(Canvas)} at the end of its onDraw (inside its scaled canvas),
 *   - passes every touch to {@link #onTouch(MotionEvent, float, float, float)} together with its
 *     screen-to-logical mapping; it returns true if the pad used the touch,
 *   - reads {@link #isDown(int)} for held keys (e.g. "hold the flute") and/or gets
 *     press/release callbacks through {@link Listener}.
 * Key codes are Android KeyEvent codes, so a real keyboard can feed the same Listener
 * from Activity.onKeyDown/onKeyUp.
 * Multi-touch is supported: e.g. hold LEFT with one finger and tap SPACE with another.
 */
public final class ControlPad {

    public interface Listener {
        void keyDown(int keyCode);

        void keyUp(int keyCode);
    }

    public static final int LEFT = KeyEvent.KEYCODE_DPAD_LEFT;
    public static final int RIGHT = KeyEvent.KEYCODE_DPAD_RIGHT;
    public static final int UP = KeyEvent.KEYCODE_DPAD_UP;
    public static final int DOWN = KeyEvent.KEYCODE_DPAD_DOWN;
    public static final int SPACE = KeyEvent.KEYCODE_SPACE;
    public static final int TAB = KeyEvent.KEYCODE_TAB;

    private static final class Key {
        final int code;
        final RectF rect;
        final String label;
        int pointer = -1;  // pointer id holding it, -1 = up

        Key(int code, RectF rect, String label) {
            this.code = code;
            this.rect = rect;
            this.label = label;
        }
    }

    private final List<Key> keys = new ArrayList<>();
    private final Listener listener;
    private final Paint fill = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final TextPaint text = new TextPaint(Paint.ANTI_ALIAS_FLAG);
    private int alpha = 200;

    public ControlPad(Listener listener) {
        this.listener = listener;
        text.setColor(Color.WHITE);
        text.setFakeBoldText(true);
    }

    /** Adds a key. label null = draw an arrow for the DPAD codes. */
    public ControlPad add(int code, float left, float top, float width, float height, String label) {
        keys.add(new Key(code, new RectF(left, top, left + width, top + height), label));
        return this;
    }

    /** Convenience: a plus-shaped arrow cluster with its top-left corner at (x, y). */
    public ControlPad addArrows(float x, float y, float size, boolean upDown) {
        add(LEFT, x, y + size, size, size, null);
        add(RIGHT, x + 2 * size, y + size, size, size, null);
        if (upDown) {
            add(UP, x + size, y, size, size, null);
            add(DOWN, x + size, y + 2 * size, size, size, null);
        }
        return this;
    }

    public void setAlpha(int alpha) {
        this.alpha = alpha;
    }

    public boolean isDown(int code) {
        for (Key k : keys) {
            if (k.code == code && k.pointer != -1) {
                return true;
            }
        }
        return false;
    }

    /** Releases everything, e.g. when the game pauses. */
    public void releaseAll() {
        for (Key k : keys) {
            if (k.pointer != -1) {
                k.pointer = -1;
                if (listener != null) listener.keyUp(k.code);
            }
        }
    }

    /**
     * Feed a touch event. scaleToLogical / offset describe how screen pixels map to the game's
     * logical layout: logicalX = (screenX - offsetX) / scale.
     */
    public boolean onTouch(MotionEvent e, float offsetX, float offsetY, float scale) {
        boolean used = false;
        int action = e.getActionMasked();
        int index = e.getActionIndex();
        switch (action) {
            case MotionEvent.ACTION_DOWN:
            case MotionEvent.ACTION_POINTER_DOWN: {
                Key k = keyAt((e.getX(index) - offsetX) / scale, (e.getY(index) - offsetY) / scale);
                if (k != null && k.pointer == -1) {
                    k.pointer = e.getPointerId(index);
                    if (listener != null) listener.keyDown(k.code);
                    used = true;
                }
                break;
            }
            case MotionEvent.ACTION_MOVE:
                // A finger sliding off a key releases it; sliding onto another key presses that one.
                for (int i = 0; i < e.getPointerCount(); i++) {
                    int id = e.getPointerId(i);
                    Key held = keyHeldBy(id);
                    Key now = keyAt((e.getX(i) - offsetX) / scale, (e.getY(i) - offsetY) / scale);
                    if (held != null && held != now) {
                        held.pointer = -1;
                        if (listener != null) listener.keyUp(held.code);
                        held = null;
                    }
                    if (held == null && now != null && now.pointer == -1) {
                        now.pointer = id;
                        if (listener != null) listener.keyDown(now.code);
                    }
                    used |= now != null;
                }
                break;
            case MotionEvent.ACTION_UP:
            case MotionEvent.ACTION_POINTER_UP: {
                Key held = keyHeldBy(e.getPointerId(index));
                if (held != null) {
                    held.pointer = -1;
                    if (listener != null) listener.keyUp(held.code);
                    used = true;
                }
                break;
            }
            case MotionEvent.ACTION_CANCEL:
                releaseAll();
                break;
            default:
                break;
        }
        return used;
    }

    /** True if the logical point is on any key (lets games ignore board taps under the pad). */
    public boolean contains(float x, float y) {
        return keyAt(x, y) != null;
    }

    public void draw(Canvas canvas) {
        for (Key k : keys) {
            boolean down = k.pointer != -1;
            fill.setColor(down ? 0xFF6FBF4A : 0xFF2F6B24);
            fill.setAlpha(alpha);
            canvas.drawRoundRect(k.rect, 8, 8, fill);
            fill.setColor(Color.WHITE);
            fill.setAlpha(alpha);
            if (k.label == null) {
                drawArrow(canvas, k);
            } else {
                float size = Math.min(k.rect.height() * 0.45f, 16f);
                text.setTextSize(size);
                text.setAlpha(alpha);
                float w = text.measureText(k.label);
                canvas.drawText(k.label, k.rect.centerX() - w / 2f, k.rect.centerY() + size / 3f, text);
            }
        }
    }

    private void drawArrow(Canvas canvas, Key k) {
        float cx = k.rect.centerX(), cy = k.rect.centerY();
        float s = Math.min(k.rect.width(), k.rect.height()) * 0.28f;
        Path p = new Path();
        switch (k.code) {
            case KeyEvent.KEYCODE_DPAD_LEFT:
                p.moveTo(cx - s, cy); p.lineTo(cx + s, cy - s); p.lineTo(cx + s, cy + s);
                break;
            case KeyEvent.KEYCODE_DPAD_RIGHT:
                p.moveTo(cx + s, cy); p.lineTo(cx - s, cy - s); p.lineTo(cx - s, cy + s);
                break;
            case KeyEvent.KEYCODE_DPAD_UP:
                p.moveTo(cx, cy - s); p.lineTo(cx - s, cy + s); p.lineTo(cx + s, cy + s);
                break;
            default:
                p.moveTo(cx, cy + s); p.lineTo(cx - s, cy - s); p.lineTo(cx + s, cy - s);
                break;
        }
        p.close();
        canvas.drawPath(p, fill);
    }

    private Key keyAt(float x, float y) {
        for (Key k : keys) {
            if (k.rect.contains(x, y)) {
                return k;
            }
        }
        return null;
    }

    private Key keyHeldBy(int pointerId) {
        for (Key k : keys) {
            if (k.pointer == pointerId) {
                return k;
            }
        }
        return null;
    }
}
