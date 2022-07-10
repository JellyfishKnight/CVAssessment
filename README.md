# 关于装甲板识别以及单目测距和姿态解算部分
***
## 类说明:
>
>    
>   (1) **PreProcess类**
>    >**用于预处理部分**
>  
>   (2) **ranging类**
>    >**用于单目测距以及相机姿态解算**
>  
>   (3) **System类**
>    >**运行类,控制以上两个类以及识别装甲板部分** 
***
## 效果说明:
### 须知: 本程序仅在赛场内录视频上调试过,具体到相机的话参数是需要修改的
#### (并且效果不能保证)
> (1) **目前在单目测距部分很不稳定,但是根据重投影的误差估算来看误差并不大,两个结果反映是不正确的**
> 
> (2) **在姿态解算上的问题也比较大,后续预计重读其原理过后再进行更新**
> 
> (3) **基本上正确部分的效果图如下**
>
> ![](https://github.com/JellyfishKnight/CVAssessment/tree/main/image/image1.jpg)
>
> (4) **误差较大的效果图如下**
> 
> ![](https://github.com/JellyfishKnight/CVAssessment/tree/main/image/image2.jpg)
***
**特别鸣谢:东南大学2019年的视觉开源提供了装甲板筛选思路**