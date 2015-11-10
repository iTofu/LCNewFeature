## LCNewFeature
几行代码快速集成新特性界面!

![image](https://github.com/LeoiOS/LCNewFeature/blob/master/ScreenShot.png)

### 前言 Foreword
每次拿到一个项目的时候，头疼的几件事之一就是新特性界面，写一堆代码做一个简单的东西。所以抽空写了个快速集成新特性界面的框架，传了上来。

### 代码 Code
* 下面是示例代码，请多参考Demo！！
* 
  - 方法一：[CocoaPods](https://cocoapods.org/) 导入：`pod 'LCNewFeature'`
  - 方法二：在Demo中找到`LCNewFeature`文件夹，拖拽到你的项目中。
* 在`AppDelegate.m`文件中，导入头文件：`#import "LCNewFeature.h"`，参考下列代码快速集成：
    
    ```objc
    BOOL showNewFeature = [LCNewFeatureVC shouldShowNewFeature];
    
    if (showNewFeature) {   // 如果需要显示新特性界面
        
        __weak typeof(self) weakSelf = self;
        LCNewFeatureVC *newFeatureVC = [LCNewFeatureVC newFeatureWithImageName:@"new_feature"
                                                                    imageCount:3
                                                                showPageControl:YES
                                                                    finishBlock:^{
        
                                                                        [weakSelf enterMainVC];
                                                                    }];
        
        self.window.rootViewController = newFeatureVC;
        
    } else {    // 如果不需要显示新特性界面
        
        [self enterMainVC];
    }
    ```
    
* `enterMainVC`(进入主界面)方法参考：
    
    ```objc
    - (void)enterMainVC {
        
        UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
        
        self.window.rootViewController = storyboard.instantiateInitialViewController;
    }
    ```

* 有一些神奇的地方，比如赋值只需要传一次图片名是为什么？其实是这样的，你需要按以下规范来给图片命名：（这其实是美工的事:)）
    ```
    比如图片原名：`NewFeature@2x.png`
    
    规范：
    `NewFeature_1@2x.png`   将作为第一张图展示
    `NewFeature_2@2x.png`   将作为第二张图展示
    ...
    ```

* 那么怎么适配不同尺寸的屏幕呢？简单，不用动代码，还是规范图片命名：（这还是美工的事:)）
    ```
    比如图片原名：`NewFeature_1@2x.png` 
    
    规范：
    `NewFeature_1@2x.png`           将展示在iPhone4/4S上
    `NewFeature_1_iphone5@2x.png`   将展示在iPhone5/5S上
    `NewFeature_1_iphone6@2x.png`   将展示在iPhone6上
    `NewFeature_1_iphone6p@2x.png`  将展示在iPhone6Plus上
```

### 更新日志 2015.11.09 Update Logs (Tag: 1.0.2)
* 添加对 CocoaPods 的支持：`pod 'LCNewFeature'`

### 更新日志 2015.05.05 Update Logs (Tag: 1.0.0)
* 添加一些界面跳转的动画效果。

### 提示 Tips
* 提供了两种进入主界面的方式：
    
    ```objc
    + (instancetype)newFeatureWithImageName:(NSString *)imageName imageCount:(NSInteger)imageCount showPageControl:(BOOL)showPageControl finishBlock:(finishBlock)finishBlock;
        将通过一直左划的方式，通过block回调进入主界面。
    + (instancetype)newFeatureWithImageName:(NSString *)imageName imageCount:(NSInteger)imageCount showPageControl:(BOOL)showPageControl enterButton:(UIButton *)enterButton;
        将在最后一张新特性图片上添加一个按钮，然后点击按钮进入主界面，按钮的属性设置好再传入（参考Demo中的代码）。
    ```

* 上述方法都是类方法，也提供了实例方法`initWith...`什么的，视个人习惯调用。

* 提供了一些属性，可选设置：

    - 当前点(分页控制器)的颜色：`pointCurrentColor`
    - 其他点(分页控制器)的颜色：`pointOtherColor`
    - 状态栏样式：`statusBarStyle`

* 记住一句话：经理可以顶，职位可以辞，但是服务器的哥们和美工的妹子绝对不能惹！2333

* 多参考Demo，如果还有问题或者建议，请联系我，我也想做的更好！联系方式在下面:)

### 联系 Support
* 发现问题请Issues我，谢谢:)
* Email: leoios@sina.com
* Website:  http://www.leodong.com/

### 授权 License
本项目采用 [MIT license](http://opensource.org/licenses/MIT) 开源，你可以利用采用该协议的代码做任何事情，只需要继续继承 MIT 协议即可。
