Pod::Spec.new do |s|

  s.name         = "LCNewFeature"
  s.version      = "1.0.5"
  s.summary      = "Finish new feature interface with a few lines of code. Support: http://LeoDev.me"
  s.homepage     = "https://github.com/LeoiOS/LCNewFeature"
  # s.license      = "MIT"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author             = { "Leo" => "devtip@163.com" }
  s.social_media_url   = "http://LeoDev.me"
  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/LeoiOS/LCNewFeature.git", :tag => s.version }
  s.source_files  = "LCNewFeature/*"
  s.requires_arc = true

end
