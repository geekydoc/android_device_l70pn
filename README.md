CyanogenMod 14.1 device configuration for LG L Fino l70pn (D290n)


How to build:
-------------

Initializing a Build Environment:

    https://source.android.com/source/initializing.html

Initialize repo:

    repo init -u git://github.com/CyanogenMod/android.git -b cm-14.1

    curl --create-dirs -L -o .repo/local_manifests/local_manifest.xml -O -L https://raw.githubusercontent.com/geekydoc/android_local_manifest/cm-14.1/local_manifest.xml
    
    
    repo sync
    
Compile:

    . build/envsetup.sh
    brunch cm_l70pn-userdebug
