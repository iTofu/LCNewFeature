# LCNewFeature

[![Travis](https://img.shields.io/travis/iTOfu/LCNewFeature.svg?style=flat)](https://travis-ci.org/iTOfu/LCNewFeature)
[![CocoaPods](https://img.shields.io/cocoapods/v/LCNewFeature.svg)](http://cocoadocs.org/docsets/LCNewFeature)
[![CocoaPods](https://img.shields.io/cocoapods/l/LCNewFeature.svg)](https://raw.githubusercontent.com/iTOfu/LCNewFeature/master/LICENSE)
[![CocoaPods](https://img.shields.io/cocoapods/p/LCNewFeature.svg)](http://cocoadocs.org/docsets/LCNewFeature)
[![LeoDev](https://img.shields.io/badge/blog-LeoDev.me-brightgreen.svg)](http://leodev.me)

几行代码快速集成新特性界面!

![LCNewFeature](https://raw.githubusercontent.com/iTofu/LCNewFeature/master/ScreenShot.png)

````
In me the tiger sniffs the rose.

心有猛虎，细嗅蔷薇。
````

欢迎访问 **[我的博客](http://LeoDev.me)** ~



## 前言 Foreword

每次拿到一个项目的时候，头疼的几件事之一就是新特性界面，写一堆代码做一个简单的东西。所以抽空写了个快速集成新特性界面的框架，传了上来共享之~



## 代码 Code

* 下面是示例代码，请多参考Demo！！

* 两种集成方法任选一：

  - 方法一：[CocoaPods](https://cocoapods.org/) 导入：`pod 'LCNewFeature'`
  - 方法二：在Demo中找到 `LCNewFeature` 文件夹，拖拽到你的项目中。

* 在 `AppDelegate.m` 文件中，导入头文件：`#import "LCNewFeature.h"`，参考下列代码快速集成：

  ````objc
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
  ````

* `enterMainVC` (进入主界面) 方法参考：

  ````objc
  - (void)enterMainVC {

      UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];

      self.window.rootViewController = storyboard.instantiateInitialViewController;
  }
  ````

* 回调当前页码的 delegate：(``@optional`)

  ````objc  
  // 当前页码的代理
  newFeatureVC.delegate = self;

  // ...

  #pragma mark - LCNewFeatureVC Delegate

  /**
   *  代理方法，回调当前页码
   *
   *  @param newFeatureVC 控制器
   *  @param page         当前页码
   */
  - (void)newFeatureVC:(LCNewFeatureVC *)newFeatureVC page:(NSInteger)page {
      NSLog(@"%@ -> Page: %d", newFeatureVC, (int)page);
  }
  ````

* 有一些神奇的地方，比如赋值只需要传一次图片名是为什么？其实是这样的，你需要按以下规范来给图片命名：（这其实是美工的事:)）

  ````
  比如图片原名：`NewFeature@2x.png`

  规范：
  `NewFeature_1@2x.png`   将作为第一张图展示
  `NewFeature_2@2x.png`   将作为第二张图展示
  ...
  ````

* 那么怎么适配不同尺寸的屏幕呢？简单，不用动代码，还是规范图片命名：（这还是美工的事:)）

  ````
  比如图片原名：`NewFeature_1@2x.png`

  规范：
  `NewFeature_1@2x.png`           将展示在 iPhone 4 / 4s 上
  `NewFeature_1_iphone5@2x.png`   将展示在 iPhone 5 / 5s 上
  `NewFeature_1_iphone6@2x.png`   将展示在 iPhone 6 / 6s 上
  `NewFeature_1_iphone6p@2x.png`  将展示在 iPhone 6 p / 6s p 上
  ````



## 版本 Release

### V 1.1.2 (2016.04.22)

* 添加代理协议，回调当前页码。详见 [Issue 5](https://github.com/iTofu/LCNewFeature/issues/5)。


### V 1.1.1 (2016.04.05)

* 更新 CocoaPods 源地址。


### V 1.1.0 (2016.03.23)

* 添加跳过按钮。

  ````objc
  __weak typeof(self) weakSelf = self;

  newFeatureVC.showSkip = YES;
  newFeatureVC.skipBlock = ^(void) {
      [weakSelf enterMainVC]; // 进入首页
  };
  ````


### V 1.0.3 (2015.12.07)

* Demo 中添加演示：切换 RootVC 时，如何搞淡入淡出效果。😈😈



### V 1.0.3 (2015.11.13)

* 添加对 iPhone 6 / 6s / 6 p / 6s p 的放大模式的支持，感谢 [RobinChao](https://github.com/RobinChao) 等同学的提醒。

* 已针对放大模式进行了显示测试和边框校对，例：Demo 中的 iPhone 6 / 6s 第一张启动图。(根目录下有个 PSD 文件，参考修改)附：放大模式下屏幕分辨率：
  - iPhone 6 / 6s 的放大模式下，屏幕分辨率为：640 x 1136 (框架将使用 iPhone 5 的图)
  - iPhone 6 p / 6s p 的放大模式下，屏幕分辨率为：1125 x 2001 (框架将使用 iPhone 6 p 的图)


### V 1.0.2 (2015.11.09)

* 添加对 [CocoaPods](https://cocoapods.org/) 的支持：`pod 'LCNewFeature'`


### V 1.0.0 (2015.05.05)

* 初始化提交。

* 添加一些界面跳转的动画效果。



## 提示 Tips

* 提供了两种进入主界面的方式：

    ```objc
    + (instancetype)newFeatureWithImageName:(NSString *)imageName imageCount:(NSInteger)imageCount showPageControl:(BOOL)showPageControl finishBlock:(finishBlock)finishBlock;
        将通过一直左划的方式，通过block回调进入主界面。
    + (instancetype)newFeatureWithImageName:(NSString *)imageName imageCount:(NSInteger)imageCount showPageControl:(BOOL)showPageControl enterButton:(UIButton *)enterButton;
        将在最后一张新特性图片上添加一个按钮，然后点击按钮进入主界面，按钮的属性设置好再传入（参考Demo中的代码）。
    ```

* 上述方法都是类方法，也提供了实例方法 `initWith...` 什么的，视个人习惯调用。

* 提供了一些属性，可选设置：

    - 当前点(分页控制器)的颜色：`pointCurrentColor`
    - 其他点(分页控制器)的颜色：`pointOtherColor`
    - 状态栏样式：`statusBarStyle`

* 记住一句话：经理可以顶，职位可以辞，但是服务器的哥们和美工的妹子绝对不能惹！2333

* 多参考 Demo，如果还有问题或者建议，请联系我，我也想做的更好！联系方式在下面:)



## 联系 Support

* 发现问题请直接 Issue，谢谢 :)

* Mail: devtip@163.com

* Blog: http://LeoDev.me


## 授权 License

本项目采用 [MIT license](http://opensource.org/licenses/MIT) 开源，你可以利用采用该协议的代码做任何事情，只需要继续继承 MIT 协议即可。
