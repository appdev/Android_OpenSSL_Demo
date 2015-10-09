# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
include $(CLEAR_VARS)

LOCAL_MODULE    := aes
LOCAL_MODULE_FILENAME    := libaes
LOCAL_SRC_FILES := aes-jni.c base64.c AES.c

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
#LOCAL_LDLIBS += -L$(SYSROOT)/lib/ -llog -lz -lcrypto -lssl

#LOCAL_LDLIBS += -L$(LOCAL_PATH)/lib -llog -lz -lcrypto -lssl

include $(BUILD_SHARED_LIBRARY)


