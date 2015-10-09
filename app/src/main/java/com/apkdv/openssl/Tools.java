/*
 * LengYue Copyright (C) 2015 www.apkdv.com
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.apkdv.openssl;

/**
 * Created by lengyue on 15/10/8.
 *
 * @author lengyue
 * @version V1.0
 * @PackageName: com.apkdv.openssl
 * @Description:
 * @date 15/10/8
 */
public class Tools {
    public static native String StringFromJNI();
    public static native String Encode(String strIn);
    public static native String Decode(String strIn);

    static {
        System.loadLibrary("aes");
    }
}
