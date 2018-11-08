Pod::Spec.new do |s|

  s.name     = "TalkfunLoggerFramework"
  s.version  = "1.2.1"
  s.license  = "MIT"
  s.summary  = "A ChannelListView with CollectionView by swift, it is like NetEaseNews Channel style.dddd"
  s.homepage = "https://github.com/20427740/TalkfunLoggerFramework"
  s.authors  = { 'Mattt Thompson' => 'm@mattt.me' }
  s.source   = { :git => 'https://github.com/20427740/TalkfunLoggerFramework.git', :tag => s.version, :submodules => true }
  s.requires_arc = true
  s.vendored_frameworks =  'SDK/TalkfunLoggerFramework.framework'
  s.ios.deployment_target = "8.0"
  
   

  
  
  
end

