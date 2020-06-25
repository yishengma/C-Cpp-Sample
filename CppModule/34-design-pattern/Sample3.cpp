//
// Created by 海盗的帽子 on 2020/6/24.
//


//代理模式

//通过代理类，来实现实际对象的访问控制权限
class VideoSite {
public:
    virtual void freeMovie() = 0;
    virtual void vipMovie() = 0;
};

class FixBugVideoSite : public VideoSite{
public:
    void freeMovie() override {

    }

    void vipMovie() override {

    }
};

class VideoSiteProxy : public VideoSite {
public:
    void freeMovie() override {
        videoSite->freeMovie();
    }

    void vipMovie() override {
        //不是vip 用户，不能访问
    }

private:
    VideoSite* videoSite;
};

