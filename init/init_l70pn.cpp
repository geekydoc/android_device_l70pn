/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"



#define CHUNK 2048 /* read 2048 bytes at a time */
#define ISMATCH(a, b) (!strncmp((a), (b), PROP_VALUE_MAX))

int check_cmdline(const char param[]) {

    char buf[CHUNK];
    FILE *file;
    size_t nread;
    file = fopen("/proc/cmdline", "r");
    if (file) {
        while ((nread = fread(buf, 1, sizeof buf, file)) > 0) {
                /* fwrite(buf, 1, nread, stdout); */
                char delims[] = " ";
                char *word = NULL;
                word = strtok(buf, delims);

                while(word != NULL) {
                        if (!strcmp(param,word)) {
                                fclose(file);
                                return 1;
                        }
                        word = strtok(NULL, delims);
                }
        }
    }	
    fclose(file);
    return 0;
}

 
void vendor_load_properties()
{
    char serial[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];


    property_get("ro.boot.serialno", serial);
    if (strncmp(serial, "LGD290", 6) == 0) {
        if (check_cmdline("model.name=LG-D290n") == 1) {
                property_set("ro.product.device", "l70pn");
                property_set("ro.product.model", "LG-D290n");
                property_set("ro.nfc.port", "I2C");
        } else {
                property_set("ro.product.device", "l70p");
                property_set("ro.product.model", "LG-D290");
        }
        property_set("ro.build.description", "l70pn_global_com-user 4.4.2/KOT49I.A1414595997/1414595997:user/release-keys");
        property_set("ro.build.fingerprint", "lge/l70pn_global_com/l70pn:4.4.2/KOT49I.A1414595997/1414595997:user/release-keys");
        property_set("persist.radio.multisim.config", "");
        property_set("telephony.lteOnCdmaDevice", "0");
    } else if (strncmp(serial, "LGD295", 6) == 0) {
        property_set("ro.product.device", "l70pds");
        property_set("ro.product.model", "LG-D295");
        property_set("ro.build.description", "l70pds_global_com-user 4.4.2 KOT49I.D29510d D29510d.1423726485 release-keys");
        property_set("ro.build.fingerprint", "lge/l70pds_global_com-user/l70pn:4.4.2/KOT49I.D29510d/D29510d.1423726485:user/release-keys");
                property_set("persist.radio.multisim.config", "dsds");
        property_set("telephony.lteOnCdmaDevice", "0");
    } else {
        /* XXX */
        property_set("ro.product.device", "l70p");
        property_set("ro.product.model", "Please write your model name to Panos");
        property_set("persist.radio.multisim.config", "");
        property_set("telephony.lteOnCdmaDevice", "0");
    }
    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    INFO("Found hardware id: %s setting build properties for %s device\n", serial, devicename);
}
