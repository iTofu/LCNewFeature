## LCNewFeature
几行代码快速集成新特性界面!

## 前言
每次拿到一个项目的时候，头疼的几件事之一就是新特性界面，写一堆代码做一个简单的东西。所以写了个快速集成新特性界面的框架，传了上来。

## 代码
* 在Demo中找到`LCNewFeature`文件夹，拖拽到你的项目中。
* 在`AppDelegate.m`文件中，导入头文件：`#import "LCNewFeature.h"`，参考一下代码进行快速集成：
    
    ```
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
    
    ```
    - (void)enterMainVC {
        
        UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
        
        self.window.rootViewController = storyboard.instantiateInitialViewController;
    }
    ```

* 有一些神奇的地方，比如赋值只需要传一次图片名是为什么？其实是这样的，你需要按以下规范来给图片命名：（这其实是美工的事:)）
    比如图片原名：`NewFeature@2x.png`
    
    规范：
    `NewFeature_1@2x.png`   将作为第一张图展示
    `NewFeature_2@2x.png`   将作为第二张图展示
    ...

* 那么怎么适配不同尺寸的屏幕呢？简单，不用动代码，还是规范图片命名：（这还是美工的事:)）
    比如图片原名：`NewFeature_1@2x.png` 
    
    规范：
    `NewFeature_1@2x.png`           将展示在iPhone4/4S上
    `NewFeature_1_iphone5@2x.png`   将展示在iPhone5/5S上
    `NewFeature_1_iphone6@2x.png`   将展示在iPhone6上
    `NewFeature_1_iphone6p@2x.png`  将展示在iPhone6Plus上

## Tips
* 提供了两种进入主界面的方式：
    - `+ (instancetype)newFeatureWithImageName:(NSString *)imageName imageCount:(NSInteger)imageCount showPageControl:(BOOL)showPageControl finishBlock:(finishBlock)finishBlock;`，将通过一直左划的方式，通过block回调进入主界面。
    - `+ (instancetype)newFeatureWithImageName:(NSString *)imageName imageCount:(NSInteger)imageCount showPageControl:(BOOL)showPageControl enterButton:(UIButton *)enterButton;`，将在最后一张新特性图片上添加一个按钮，然后点击按钮进入主界面，按钮的属性设置好再传入（参考Demo中的代码）。

* 提供了一些属性，可选设置：
    - 当前点(分页控制器)的颜色：`pointCurrentColor`。
    - 其他点(分页控制器)的颜色：`pointOtherColor`。
    - 状态栏样式：`statusBarStyle`。

## 联系
* 发现问题请lssues我，谢谢:)
* Email: leoios@sina.com
