Pod::Spec.new do |s|

  s.name         = "LCNewFeature"
  s.version      = "1.0.0"
  s.summary      = "Finish new feature interface with a few lines of code."
  s.homepage     = "https://github.com/LeoiOS/LCNewFeature"
  # s.license      = "MIT"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author             = { "Leo" => "leoios@sina.com" }
  s.social_media_url   = "http://www.leodong.com"
  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/LeoiOS/LCNewFeature.git", :tag => s.version }
  s.source_files  = "LCNewFeature/*"
  s.requires_arc = true

end
