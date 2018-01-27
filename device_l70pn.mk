#
# Copyright (C) 2013 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)

# Specific overlay
DEVICE_PACKAGE_OVERLAYS += device/lge/l70pn/overlay

PRODUCT_PACKAGES += Torch

# NFC packages
PRODUCT_PACKAGES += \
    NfcNci \
    libnfc-nci \
    nfc_nci.pn54x.default \
    Tag \
    com.android.nfc_extras

NFCEE_ACCESS_PATH := device/lge/l70pn/prebuilt/etc/nfcee_access.xml

PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.nfc.xml:system/etc/permissions/android.hardware.nfc.xml \
    frameworks/native/data/etc/android.hardware.nfc.hce.xml:system/etc/permissions/android.hardware.nfc.hce.xml \
    frameworks/native/data/etc/com.android.nfc_extras.xml:system/etc/permissions/com.android.nfc_extras.xml \
    device/lge/l70pn/prebuilt/etc/libnfc-brcm.conf:system/etc/libnfc-brcm.conf \
    device/lge/l70pn/prebuilt/etc/nfc-nci.conf:system/etc/nfc-nci.conf \
    device/lge/l70pn/prebuilt/etc/libnfc-nxp.conf:system/etc/libnfc-nxp.conf \
    device/lge/l70pn/prebuilt/etc/nfcee_access.xml:system/etc/nfcee_access.xml \
    device/lge/l70pn/fstab.msm8610:root/fstab.msm8610

PRODUCT_LOCALES := en_US
PRODUCT_LOCALES += hdpi
PRODUCT_AAPT_CONFIG := normal hdpi
PRODUCT_AAPT_PREF_CONFIG := hdpi

$(call inherit-product, vendor/lge/l70pn/l70pn-vendor.mk)

# Inherit from msm8610-common
$(call inherit-product, device/lge/msm8610-common/msm8610.mk)

