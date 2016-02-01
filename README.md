CyanogenMod 12.1 device configuration for LG L Fino l70pn (D290n), semi-compatible with l70pds (D295)


How to build:
-------------

Initializing a Build Environment:

    https://source.android.com/source/initializing.html

Initialize repo:

    repo init -u git://github.com/CyanogenMod/android.git -b cm-12.1

    curl --create-dirs -L -o .repo/local_manifests/local_manifest.xml -O -L https://raw.githubusercontent.com/meganukebmp/android_local_manifest/master/local_manifest.xml
    
    repo sync

Compile:

    . build/envsetup.sh
    brunch cm_l70pn-userdebug
