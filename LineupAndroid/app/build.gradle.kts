plugins {
    id("com.android.application")
}

android {
    namespace = "com.teff.puzzles"
    compileSdk = 37

    defaultConfig {
        applicationId = "com.teff.puzzles"
        minSdk = 24
        targetSdk = 37
        versionCode = 1
        versionName = "1.0"
    }

    buildTypes {
        release {
            isMinifyEnabled = false
            // Personal sideload build: sign with the debug key so the APK installs directly.
            signingConfig = signingConfigs.getByName("debug")
        }
    }

    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_17
        targetCompatibility = JavaVersion.VERSION_17
    }

    androidResources {
        // Sounds and music are opened with openFd(), which needs them stored uncompressed.
        noCompress += listOf("wav", "mid")
    }
}
