#!/sbin/sh

model=`cat /proc/cmdline | awk '{print $16}'| awk -F= '{print $2}'`


case $model in
     "LG-D290")
	rm /system/etc/permissions/android.hardware.nfc.xml
	rm /system/etc/permissions/android.hardware.nfc.hce.xml
	cat /system/usr/keylayout/Generic-D290.kl > /system/usr/keylayout/Generic.kl
          ;;
     "LG-D290n")
	cat /system/usr/keylayout/Generic-D290.kl > /system/usr/keylayout/Generic.kl
          ;;
     "LG-D295")
	rm /system/etc/permissions/android.hardware.nfc.xml
	rm /system/etc/permissions/android.hardware.nfc.hce.xml
	cat /system/usr/keylayout/Generic-D295.kl > /system/usr/keylayout/Generic.kl
          ;; 
     "LG-D295f8")
	rm /system/etc/permissions/android.hardware.nfc.xml
	rm /system/etc/permissions/android.hardware.nfc.hce.xml
	cat /system/usr/keylayout/Generic-D295.kl > /system/usr/keylayout/Generic.kl
          ;;
     "LG-D290f8")
	rm /system/etc/permissions/android.hardware.nfc.xml
	rm /system/etc/permissions/android.hardware.nfc.hce.xml
	cat /system/usr/keylayout/Generic-D290.kl > /system/usr/keylayout/Generic.kl
	;;
     "LG-D295F8")
	rm /system/etc/permissions/android.hardware.nfc.xml
	rm /system/etc/permissions/android.hardware.nfc.hce.xml
	cat /system/usr/keylayout/Generic-D295.kl > /system/usr/keylayout/Generic.kl
          ;;
     "LG-D290F8")
	rm /system/etc/permissions/android.hardware.nfc.xml
	rm /system/etc/permissions/android.hardware.nfc.hce.xml
	cat /system/usr/keylayout/Generic-D290.kl > /system/usr/keylayout/Generic.kl
          ;;
     *)
	rm /system/etc/permissions/android.hardware.nfc.xml
	rm /system/etc/permissions/android.hardware.nfc.hce.xml
          ;;
esac
