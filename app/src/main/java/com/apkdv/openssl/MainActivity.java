package com.apkdv.openssl;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView textView = (TextView)findViewById(R.id.mTextView);

        String str1 = Tools.Encode("LengYue");

        String str2 = Tools.Decode(str1);

        textView.setText(str1 + "  Decode:  " + str2);


        // String s = AESUtil.StringFromJNI();//Encode("hello");

        //Log.i("jnitag", s);
    }
}
