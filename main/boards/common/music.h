#ifndef MUSIC_H
#define MUSIC_H

#include <string>

class Music {
public:
    virtual ~Music() = default;  // 添加虚析构函数
    virtual bool PlayUrl(const std::string& title,const std::string& url,const std::string& lyric_url) = 0;
    virtual bool Download(const std::string& song_name,int type) = 0;
    virtual bool Play() = 0;
    virtual bool Stop() = 0;
    virtual std::string GetDownloadResult() = 0;
    
    // 新增流式播放相关方法
    virtual bool StartStreaming(const std::string& music_url) = 0;
    virtual bool StopStreaming() = 0;  // 停止流式播放
    virtual size_t GetBufferSize() const = 0;
    virtual bool IsDownloading() const = 0;
    bool lyric_enabled_ = true;
};

#endif // MUSIC_H 