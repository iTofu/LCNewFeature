

### LCNewFeature
几行代码快速集成新特性界面!

### 前言
每次拿到一个新项目的时候，有点头疼的部分之一就是新特性界面，有点麻烦，所以写了个快速集成新特性界面的框架。

### 代码
* 在Demo中找到LCNewFeature文件夹，拖到你的项目中。
* 在`AppDelegate.m`文件里面，先导入头文件：`#import "LCNewFeature.h"`， 然后在`-application:didFinishLaunchingWithOptions:`方法中，参考下列代码调用：
    BOOL showNewFeature = [LCNewFeatureVC shouldShowNewFeature];
