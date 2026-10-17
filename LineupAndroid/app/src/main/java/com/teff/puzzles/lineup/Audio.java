package com.teff.puzzles.lineup;

import android.content.Context;
import android.content.res.AssetFileDescriptor;
import android.content.res.AssetManager;
import android.media.AudioAttributes;
import android.media.MediaPlayer;
import android.media.SoundPool;

import java.io.IOException;
import java.util.Random;

/** Original WAV effects through SoundPool, original MIDI music through MediaPlayer. */
final class Audio {
    // Indexed by the Game.SND_* ids.
    private static final String[] EFFECTS =
            {null, "APPLAUSE", "BALLS", "NOISE", "STEP", "NOBONUS", "LINECOMPLETE", "WHIST1", "WHIST2"};

    private final AssetManager assets;
    private final SoundPool pool;
    private final int[] ids = new int[EFFECTS.length];
    private final Random rnd = new Random();
    private MediaPlayer music;

    boolean soundOn = true;
    boolean musicOn = true;

    Audio(Context context) {
        assets = context.getAssets();
        pool = new SoundPool.Builder()
                .setMaxStreams(4)
                .setAudioAttributes(new AudioAttributes.Builder()
                        .setUsage(AudioAttributes.USAGE_GAME)
                        .setContentType(AudioAttributes.CONTENT_TYPE_SONIFICATION)
                        .build())
                .build();
        for (int i = 1; i < EFFECTS.length; i++) {
            try (AssetFileDescriptor fd = assets.openFd("lineup/snd/" + EFFECTS[i] + ".wav")) {
                ids[i] = pool.load(fd, 1);
            } catch (IOException e) {
                ids[i] = 0;
            }
        }
    }

    void play(int id) {
        if (soundOn && id > 0 && id < ids.length && ids[id] != 0) {
            pool.play(ids[id], 1f, 1f, 1, 0, 1f);
        }
    }

    /** Starts one of the four game tunes at random, looping. */
    void startMusic() {
        stopMusic();
        if (!musicOn) {
            return;
        }
        try (AssetFileDescriptor fd = assets.openFd("lineup/mus/MIDIGAME" + (rnd.nextInt(4) + 1) + ".mid")) {
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

    void pauseMusic() {
        if (music != null && music.isPlaying()) {
            music.pause();
        }
    }

    void resumeMusic() {
        if (music != null && musicOn) {
            music.start();
        }
    }

    void stopMusic() {
        if (music != null) {
            music.release();
            music = null;
        }
    }

    boolean hasMusic() {
        return music != null;
    }

    void release() {
        stopMusic();
        pool.release();
    }
}
