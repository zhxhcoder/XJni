package com.zhxh.xjni;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.View;

/**
 * Created by zhxh on 2018/7/25
 */
public class BombView extends View {

    private int pressure;
    private Paint paint;

    public BombView(Context context) {
        super(context);
        paint = new Paint();
        paint.setAntiAlias(true);
        paint.setTextSize(60);
    }


    public void setPressure(int pressure) {
        this.pressure = pressure;
        postInvalidate();//onDraw()执行
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);

        if (pressure > 220) {
            //1.如果压力值大于220，就绘制文本，显示锅炉爆炸了，快跑
            canvas.drawText("快跑！！，要爆了！", 50, getHeight() / 8, paint);
        } else {
            //2.正常和提示的情况
            //设置背景颜色为灰色
            paint.setColor(Color.GRAY);
            canvas.drawRect(10, 10, 60, 260, paint);
            //2.1如果是小于200正常显示，并且设置画笔颜色，绿色
            if (pressure < 200) {
                paint.setColor(Color.GREEN);
                canvas.drawRect(10, 260 - pressure, 60, 260, paint);
            } else if (pressure >= 200) {
                //2.2如果是大于200警示给看护者，并且设置画笔颜色，红色
                paint.setColor(Color.RED);
                canvas.drawRect(10, 260 - pressure, 60, 260, paint);
            }
        }

    }
}

