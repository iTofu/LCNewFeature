//
//  Created by 刘超 on 15/4/30.
//  Copyright (c) 2015年 Leo. All rights reserved.
//
//  Mail:   mailto:devtip@163.com
//  GitHub: http://github.com/iTofu
//  如有问题或建议请给我发邮件, 或在该项目的 GitHub 主页提 Issue, 谢谢:)
//
//  V 1.1.2


//  !! WARNING 必读!!

/**
 *  !!!!!! 必读 !!!!!!
 *
 *  1. 为什么传一个图片名字和图片个数就可以展示所有图片?
 *
 *      Why? No why. 按以下要求命名图片即可:
 *      第一张图: `<name>_1@2x.png`
 *      第二张图: `<name>_2@2x.png`
 *      ...
 *
 *      如:
 *      `NewFeature_1@2x.png`   将作为第一张图展示
 *      `NewFeature_2@2x.png`   将作为第二张图展示
 *      ...
 *
 *
 *  2. 怎么适配 iPhone 5 / 5s, iPhone 6 / 6s, iPhone 6 p / 6s p?
 *
 *      iPhone 5 / 5s 的图片请在名字后面拼接 `_iphone5`;
 *      iPhone 6 / 6s 的图片请在名字后面拼接 `_iphone6`;
 *      iPhone 6 p / 6s p 的图片请在名字后面拼接 `_iphone6p`;
 *
 *      如:
 *      `NewFeature_1@2x.png`           将展示在 iPhone 4 / 4s 上
 *      `NewFeature_1_iphone5@2x.png`   将展示在 iPhone 5 / 5s 上
 *      `NewFeature_1_iphone6@2x.png`   将展示在 iPhone 6 / 6s 上
 *      `NewFeature_1_iphone6p@2x.png`  将展示在 iPhone 6 p / 6s p 上
 *
 *
 *  3. 如果想变更状态栏的样式, 打开项目的 Info.plist, 先添加下列键值对, 然后 statusBarStyle 属性才会生效:
 *
 *      Key   :  View controller-based status bar appearance
 *      Value :  NO (添加 Key 后，Value 默认值就是 NO)
 *
 *
 *  4. 如果还有问题或者建议, 请联系我, 我也想做的更好! 联系方式在顶部:)
 */



#import <UIKit/UIKit.h>


// 屏幕尺寸
#define LC_NEW_FEATURE_SCREEN_SIZE  [UIScreen mainScreen].bounds.size

@class LCNewFeatureVC;

/**
 *  完成新特性界面展示后的block回调
 */
typedef void (^LCNewFeatureFinishBlock)();

//typedef void (^LCNewFeaturePageBlock)(NSInteger page);

/**
 状态栏样式
 */
typedef enum : NSUInteger {
    LCStatusBarStyleBlack,  // 黑色
    LCStatusBarStyleWhite,  // 白色
    LCStatusBarStyleNone,   // 隐藏
} LCStatusBarStyle;

/**
 设备型号
 */
typedef enum : NSUInteger {
    DeviceModelUnknow,      // 未知设备
    DeviceModeliPhone4,     // iPhone 4 / 4s
    DeviceModeliPhone56,    // iPhone 5 / 5s / 6 / 6 p / 6s / 6s p
    DeviceModeliPad,        // iPad
} DeviceModel;


@protocol LCNewFeatureVCDelegate <NSObject>

@optional

/**
 *  代理方法，回调当前页码
 *
 *  @param newFeatureVC 控制器
 *  @param page         当前页码
 */
- (void)newFeatureVC:(LCNewFeatureVC *)newFeatureVC page:(NSInteger)page;

@end



@interface LCNewFeatureVC : UIViewController



#pragma mark - 属性 Properties

/**
 *  当前点(分页控制器)的颜色
 */
@property (nonatomic, strong) UIColor *pointCurrentColor;

/**
 *  其他点(分页控制器)的颜色
 */
@property (nonatomic, strong) UIColor *pointOtherColor;

/**
 *  状态栏样式, 请先参考`必读`第3条设置
 */
@property (nonatomic, assign) LCStatusBarStyle statusBarStyle;

/**
 *  是否显示跳过按钮, 默认不显示
 */
@property (nonatomic, assign) BOOL showSkip;

/**
 *  点击跳过按钮的 block
 */
@property (nonatomic, copy) LCNewFeatureFinishBlock skipBlock;

/**
 *  代理
 */
@property (nonatomic, weak) id<LCNewFeatureVCDelegate> delegate;

///**
// *  设备型号
// */
//@property (nonatomic, assign) DeviceModel deviceModel;



#pragma mark - 方法 Methods

/**
 *  是否显示新特性视图控制器, 对比版本号得知
 */
+ (BOOL)shouldShowNewFeature;

/**
 *  初始化新特性视图控制器, 类方法
 *
 *  @param imageName 图片名, 请将原图名称修改为该格式: `<imageName>_1`, `<imageName>_2`... 如: `NewFeature_1@2x.png`
 *
 *  @param imageCount 图片个数
 *
 *  @param showPageControl 是否显示分页控制器
 *
 *  @param enterButton 进入主界面的按钮
 *
 *  @return 初始化的控制器实例
 */
+ (instancetype)newFeatureWithImageName:(NSString *)imageName
                             imageCount:(NSInteger)imageCount
                        showPageControl:(BOOL)showPageControl
                            enterButton:(UIButton *)enterButton;

/**
 *  初始化新特性视图控制器, 实例方法
 *
 *  @param imageName 图片名, 请将原图名称修改为该格式: `<imageName>_1`, `<imageName>_2`... 如: `NewFeature_1@2x.png`
 *
 *  @param imageCount 图片个数
 *
 *  @param showPageControl 是否显示分页控制器
 *
 *  @param enterButton 进入主界面的按钮
 *
 *  @return 初始化的控制器实例
 */
- (instancetype)initWithImageName:(NSString *)imageName
                       imageCount:(NSInteger)imageCount
                  showPageControl:(BOOL)showPageControl
                      enterButton:(UIButton *)enterButton;

/**
 *  初始化新特性视图控制器, 类方法
 *
 *  @param imageName 图片名, 请将原图名称修改为该格式: `<imageName>_1`, `<imageName>_2`... 如: `NewFeature_1@2x.png`
 *
 *  @param imageCount 图片个数
 *
 *  @param showPageControl 是否显示分页控制器
 *
 *  @param finishBlock 完成新特性界面展示后的回调
 *
 *  @return 初始化的控制器实例
 */
+ (instancetype)newFeatureWithImageName:(NSString *)imageName
                             imageCount:(NSInteger)imageCount
                        showPageControl:(BOOL)showPageControl
                            finishBlock:(LCNewFeatureFinishBlock)finishBlock;

/**
 *  初始化新特性视图控制器, 实例方法
 *
 *  @param imageName 图片名, 请将原图名称修改为该格式: `<imageName>_1`, `<imageName>_2`... 如: `NewFeature_1@2x.png`
 *
 *  @param imageCount 图片个数
 *
 *  @param showPageControl 是否显示分页控制器
 *
 *  @param finishBlock 完成新特性界面展示后的回调
 *
 *  @return 初始化的控制器实例
 */
- (instancetype)initWithImageName:(NSString *)imageName
                       imageCount:(NSInteger)imageCount
                  showPageControl:(BOOL)showPageControl
                      finishBlock:(LCNewFeatureFinishBlock)finishBlock;

@end
