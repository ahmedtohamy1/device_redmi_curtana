/*
 * Copyright (C) 2020 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <android-base/logging.h>
#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "property_service.h"
#include "vendor_init.h"

using android::init::property_set;

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}
void load_curtanaglobal() {
    property_override("ro.product.model", "Redmi Note 9S");
    property_override("ro.product.product.model", "Redmi Note 9S");
    property_override("ro.product.system.model", "Redmi Note 9S");
    property_override("ro.build.description", "curtana_global-user 10 QKQ1.191215.002 V11.0.8.0.QJWMIXM release-keys");
    property_override("ro.boot.verifiedbootstate", "green");
    property_override("ro.build.fingerprint", "google/walleye/walleye:8.1.0/OPM1.171019.011/4448085:user/release-keys");
    property_override("ro.vendor.build.fingerprint", "google/walleye/walleye:8.1.0/OPM1.171019.011/4448085:user/release-keys");
    property_override("ro.product.mod_device", "curtana_global");
}

void load_curtana() {
    property_override("ro.product.model", "Redmi Note 9 Pro");
    property_override("ro.product.product.model", "Redmi Note 9 Pro");
    property_override("ro.product.system.model", "Redmi Note 9 Pro");
    property_override("ro.build.description", "curtana-user 10 QKQ1.191215.002 V11.0.7.0.QJWINXM release-keys");
    property_override("ro.boot.verifiedbootstate", "green");
    property_override("ro.build.fingerprint", "google/walleye/walleye:8.1.0/OPM1.171019.011/4448085:user/release-keys");
    property_override("ro.vendor.build.fingerprint", "google/walleye/walleye:8.1.0/OPM1.171019.011/4448085:user/release-keys");
    property_override("ro.product.mod_device", "curtana_in_global");
}

void vendor_load_properties() {
    std::string region = android::base::GetProperty("ro.boot.hwc", "");

    if (region.find("Global_TWO") != std::string::npos) {
        load_curtanaglobal();
    } else {
        load_curtana();
    }
}
