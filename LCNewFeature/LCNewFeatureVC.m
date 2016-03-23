//
//  Created by 刘超 on 15/4/30.
//  Copyright (c) 2015年 Leo. All rights reserved.
//
//  Email : leoios@sina.com
//  GitHub: http://github.com/LeoiOS
//  如有问题或建议请给我发 Email, 或在该项目的 GitHub 主页 Issues 我, 谢谢:)
//

#import "LCNewFeatureVC.h"
#import "UIImage+LC.h"

@interface LCNewFeatureVC () <UIScrollViewDelegate> {
    
    /** 图片名 */
    NSString *_imageName;
    
    /** 图片个数 */
    NSInteger _imageCount;
    
    /** 分页控制器 */
    UIPageControl *_pageControl;
    
    /** 是否显示分页控制器 */
    BOOL _showPageControl;
    
    /** 进入主界面的按钮 */
    UIButton *_enterButton;
    
    /** 完成新特性界面展示后的block回调 */
    finishBlock _finishBlock;
}

@property (nonatomic, weak) UIButton *skipBtn;

@end



@implementation LCNewFeatureVC

#pragma mark - 设备型号

- (DeviceModel)deviceModel {
    
    CGSize screenSize = [UIScreen mainScreen].bounds.size;
    if (10 * screenSize.height / screenSize.width == 15) {          // iPhone 4 / 4s
        
        return DeviceModeliPhone4;
        
    } else if (10 * screenSize.height / screenSize.width == 17) {   // iPhone 5 / 6 / 6 p / 6s / 6s p
        
        return DeviceModeliPhone56;
        
    }
    
    return DeviceModelUnknow;
}

#pragma mark - 是否显示新特性视图控制器

+ (BOOL)shouldShowNewFeature {
    
    NSString *key = @"CFBundleShortVersionString";
    
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    
    // 获取沙盒中版本号
    NSString *lastVersion = [defaults stringForKey:key];
    
    // 获取当前的版本号
    NSString *currentVersion = [NSBundle mainBundle].infoDictionary[key];
    
    if ([currentVersion isEqualToString:lastVersion]) {
        
        return NO;
        
    } else {
        
        [defaults setObject:currentVersion forKey:key];
        [defaults synchronize];
        
        return YES;
    }
}

#pragma mark - 初始化新特性视图控制器

+ (instancetype)newFeatureWithImageName:(NSString *)imageName
                             imageCount:(NSInteger)imageCount
                        showPageControl:(BOOL)showPageControl
                            enterButton:(UIButton *)enterButton {
    
    return [[self alloc] initWithImageName:imageName
                                imageCount:imageCount
                           showPageControl:showPageControl
                               enterButton:enterButton];
}

+ (instancetype)newFeatureWithImageName:(NSString *)imageName
                             imageCount:(NSInteger)imageCount
                        showPageControl:(BOOL)showPageControl
                            finishBlock:(finishBlock)finishBlock {
    
    return [[self alloc] initWithImageName:imageName
                                imageCount:imageCount
                           showPageControl:showPageControl
                               finishBlock:finishBlock];
}

- (instancetype)initWithImageName:(NSString *)imageName
                       imageCount:(NSInteger)imageCount
                  showPageControl:(BOOL)showPageControl
                      enterButton:(UIButton *)enterButton {
    
    if (self = [super init]) {
        
        _imageName       = imageName;
        _imageCount      = imageCount;
        _showPageControl = showPageControl;
        _enterButton     = enterButton;
        
        [self setupMainView];
    }
    
    return self;
}

- (instancetype)initWithImageName:(NSString *)imageName
                       imageCount:(NSInteger)imageCount
                  showPageControl:(BOOL)showPageControl
                      finishBlock:(finishBlock)finishBlock {
    
    if (self = [super init]) {
        
        _imageName       = imageName;
        _imageCount      = imageCount;
        _showPageControl = showPageControl;
        _finishBlock     = finishBlock;
        
        [self setupMainView];
    }
    
    return self;
}

#pragma mark 设置主界面

- (void)setupMainView {
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    // 默认状态栏样式为黑色
    self.statusBarStyle = LCStatusBarStyleBlack;
    
    // 图片数组非空时
    if (_imageCount) {
        
        // 滚动视图
        UIScrollView *scrollView = [[UIScrollView alloc] init];
        [scrollView setDelegate:self];
        [scrollView setBounces:NO];
        [scrollView setPagingEnabled:YES];
        [scrollView setShowsHorizontalScrollIndicator:NO];
        [scrollView setFrame:(CGRect){0, 0, LC_NEW_FEATURE_SCREEN_SIZE}];
        [scrollView setContentSize:(CGSize){LC_NEW_FEATURE_SCREEN_SIZE.width * _imageCount, 0}];
        [self.view addSubview:scrollView];
        
        // 滚动图片
        CGFloat imageW = LC_NEW_FEATURE_SCREEN_SIZE.width;
        CGFloat imageH = LC_NEW_FEATURE_SCREEN_SIZE.height;
        
        for (int i = 0; i < _imageCount; i++) {
            
            CGFloat imageX = imageW * i;
            NSString *realImageName = [NSString stringWithFormat:@"%@_%d", _imageName, i + 1];
            UIImage *realImage = [UIImage imageNamedForAdaptation:realImageName iphone5:YES iphone6:YES iphone6p:YES];
            
            UIImageView *imageView = [[UIImageView alloc] init];
            [imageView setImage:realImage];
            [imageView setFrame:(CGRect){imageX, 0, imageW, imageH}];
            [scrollView addSubview:imageView];
            
            if (_enterButton && i == _imageCount - 1) {
                
                [imageView setUserInteractionEnabled:YES];
                [imageView addSubview:_enterButton];
            }
        }
        
        // 分页视图
        if (_showPageControl) {
            
            UIPageControl *pageControl = [[UIPageControl alloc] init];
            [pageControl setNumberOfPages:_imageCount];
            [pageControl setHidesForSinglePage:YES];
            [pageControl setUserInteractionEnabled:NO];
            [pageControl setPageIndicatorTintColor:[UIColor lightGrayColor]];
            [pageControl setCurrentPageIndicatorTintColor:[UIColor darkGrayColor]];
            [pageControl setFrame:(CGRect){0, LC_NEW_FEATURE_SCREEN_SIZE.height * 0.9, LC_NEW_FEATURE_SCREEN_SIZE.width, 37.0f}];
            [self.view addSubview:pageControl];
            _pageControl = pageControl;
        }
        
        // 跳过按钮
        UIButton *skipBtn = [[UIButton alloc] init];
        skipBtn.hidden = YES;
        skipBtn.backgroundColor = [UIColor lightGrayColor];
        skipBtn.titleLabel.font = [UIFont systemFontOfSize:16.0f];
        
        NSString *skipTitle = @"Skip";
        NSString *currentLanguage = [[NSLocale preferredLanguages] objectAtIndex:0];
        if ([currentLanguage isEqualToString:@"zh-Hans-CN"]) {
            skipTitle = @"跳过";
        } else if ([currentLanguage isEqualToString:@"zh-Hant-CN"]) {
            skipTitle = @"跳過";
        }
        
        [skipBtn setTitle:skipTitle forState:UIControlStateNormal];
        [skipBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
        [skipBtn addTarget:self action:@selector(skipBtnClicked) forControlEvents:UIControlEventTouchUpInside];
        skipBtn.frame = CGRectMake(LC_NEW_FEATURE_SCREEN_SIZE.width - 95, 30, 80, 40);
        skipBtn.layer.cornerRadius = 20.0f;
        [self.view addSubview:skipBtn];
        self.skipBtn = skipBtn;
        
    } else {
        
        NSLog(@"警告: 请放入新特性图片!");
    }
}

- (void)skipBtnClicked {
    
    if (self.skipBlock) {
        self.skipBlock();
    }
}

- (void)setShowSkip:(BOOL)showSkip {
    _showSkip = showSkip;
    
    self.skipBtn.hidden = !self.showSkip;
}

#pragma mark - 新特性视图控制器的显示和消失

- (void)viewWillAppear:(BOOL)animated {
    
    [super viewWillAppear:animated];
    
    switch (self.statusBarStyle) {
            
        case LCStatusBarStyleBlack:
            [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleDefault];
            break;
            
        case LCStatusBarStyleWhite:
            [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
            break;
            
        case LCStatusBarStyleNone:
            [[UIApplication sharedApplication] setStatusBarHidden:YES withAnimation:UIStatusBarAnimationNone];
            break;
            
        default:
            break;
    }
    
    if (_showPageControl) {
        
        // 如果设置了分页控制器当前点的颜色
        if (self.pointCurrentColor) {
            
            [_pageControl setCurrentPageIndicatorTintColor:self.pointCurrentColor];
        }
        
        // 如果设置了分页控制器其他点的颜色
        if (self.pointOtherColor) {
            
            [_pageControl setPageIndicatorTintColor:self.pointOtherColor];
        }
    }
}

- (void)viewWillDisappear:(BOOL)animated {
    
    [super viewWillDisappear:animated];
    
    if (self.statusBarStyle == LCStatusBarStyleNone) {
        
        [[UIApplication sharedApplication] setStatusBarHidden:NO withAnimation:UIStatusBarAnimationFade];
        [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleDefault];
    }
}

#pragma mark - UIScrollViewDelegate 方法

- (void)scrollViewWillBeginDecelerating:(UIScrollView *)scrollView {
    
    // 最后一张再向左划的话
    if (scrollView.contentOffset.x == LC_NEW_FEATURE_SCREEN_SIZE.width * (_imageCount - 1)) {
        
        if (_finishBlock) {
            
            [UIView animateWithDuration:0.4f animations:^{
                
                self.view.transform = CGAffineTransformMakeTranslation(-LC_NEW_FEATURE_SCREEN_SIZE.width, 0);
                
            } completion:^(BOOL finished) {
                
                _finishBlock();
            }];
        }
    }
}

- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView {
    
    CGPoint currentPoint = scrollView.contentOffset;
    NSInteger page = currentPoint.x / scrollView.bounds.size.width;
    _pageControl.currentPage = page;
}

@end
