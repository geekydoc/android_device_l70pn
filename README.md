CyanogenMod 12.1 device configuration for LG L Fino l70pn (D290n)


How to build:
-------------

Initializing a Build Environment:

    https://source.android.com/source/initializing.html

Initialize repo:

    repo init -u git://github.com/CyanogenMod/android.git -b cm-12.1

    curl --create-dirs -L -o .repo/local_manifests/local_manifest.xml -O -L https://raw.githubusercontent.com/geekydoc/android_local_manifest/cm-13.0/local_manifest.xml
    
    
    repo sync --force-sync
    
Additional step needed for NFC to compile properly:
    
    ./NxpNfcAndroid/install_NFC.sh PN7120
    
Compile:

    . build/envsetup.sh
    brunch cm_l70pn-userdebug
