package com.teff.puzzles.common;

import android.content.Context;
import android.content.res.AssetFileDescriptor;
import android.content.res.AssetManager;
import android.media.AudioAttributes;
import android.media.MediaPlayer;
import android.media.SoundPool;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

/**
 * Shared sound helper: original WAVs through SoundPool, original MIDI music through MediaPlayer.
 * Files live in assets/&lt;gameId&gt;/snd/NAME.wav and assets/&lt;gameId&gt;/mus/NAME.mid.
 * Effects are referred to by their original resource name, e.g. play("WHIST1").
 */
public final class GameAudio {
    private final AssetManager assets;
    private final String gameId;
    private final SoundPool pool;
    private final Map<String, Integer> ids = new HashMap<>();
    private final Random rnd = new Random();
    private MediaPlayer music;

    public boolean soundOn = true;
    public boolean musicOn = true;

    public GameAudio(Context context, String gameId) {
        this.assets = context.getAssets();
        this.gameId = gameId;
        pool = new SoundPool.Builder()
                .setMaxStreams(6)
                .setAudioAttributes(new AudioAttributes.Builder()
                        .setUsage(AudioAttributes.USAGE_GAME)
                        .setContentType(AudioAttributes.CONTENT_TYPE_SONIFICATION)
                        .build())
                .build();
        try {
            String[] files = assets.list(gameId + "/snd");
            if (files != null) {
                for (String f : files) {
                    if (f.toLowerCase().endsWith(".wav")) {
                        try (AssetFileDescriptor fd = assets.openFd(gameId + "/snd/" + f)) {
                            ids.put(f.substring(0, f.length() - 4).toUpperCase(), pool.load(fd, 1));
                        }
                    }
                }
            }
        } catch (IOException ignored) {
            // no sounds for this game
        }
    }

    public void play(String name) {
        Integer id = ids.get(name.toUpperCase());
        if (soundOn && id != null) {
            pool.play(id, 1f, 1f, 1, 0, 1f);
        }
    }

    /** Starts music: the given MIDI name, or a random one of the names if several are given. */
    public void startMusic(String... names) {
        stopMusic();
        if (!musicOn || names.length == 0) {
            return;
        }
        String name = names[rnd.nextInt(names.length)];
        try (AssetFileDescriptor fd = assets.openFd(gameId + "/mus/" + name + ".mid")) {
            MediaPlayer player = new MediaPlayer();
            player.setDataSource(fd.getFileDescriptor(), fd.getStartOffset(), fd.getLength());
            player.setLooping(true);
            player.prepare();
            player.start();
            music = player;
        } catch (IOException | RuntimeException e) {
            music = null;
        }
    }

    public void pauseMusic() {
        if (music != null && music.isPlaying()) {
            music.pause();
        }
    }

    public void resumeMusic() {
        if (music != null && musicOn) {
            music.start();
        }
    }

    public void stopMusic() {
        if (music != null) {
            music.release();
            music = null;
        }
    }

    public boolean hasMusic() {
        return music != null;
    }

    public void release() {
        stopMusic();
        pool.release();
    }
}
