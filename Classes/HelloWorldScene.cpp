#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
USING_NS_CC;
using namespace ui;
using namespace cocostudio;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto layer = dynamic_cast<Layout*>(GUIReader::getInstance()->widgetFromJsonFile("Export/TestUI_1/TestUI_1.json"));
    auto label = dynamic_cast<Text*>(layer->getChildByName("Label_2"));
    if (label)
    {
        label->setString("文字を変更できます");
    }
    this->addChild(layer);

    log("-----------------------");
    log("layer tag:%d",layer->getTag());
    log("layer name:%s",layer->getName().c_str());
    
    showTree();
    
    return true;
}

void HelloWorld::showTree()
{
    auto layer = this->getChildByTag(3);
    auto it = layer->getChildren().begin();
    while (it != layer->getChildren().end())
    {
        log("-----------------------");
        auto node = dynamic_cast<Node*>(*it);
        if (node)
        {
            log("layer node tag:%d",node->getTag());
            log("layer node name:%s",node->getName().c_str());
            auto it2 = node->getChildren().begin();
            
            while (it2 != node->getChildren().end())
            {
                auto node2 = dynamic_cast<Node*>(*it2);
                if (node2)
                {
                    log("node tag:%d", node2->getTag());
                    log("node name:%s", node2->getName().c_str());
                    auto it3 = node2->getChildren().begin();
                    
                    while (it3 != node2->getChildren().end())
                    {
                        auto node3 = dynamic_cast<Node*>(*it3);
                        if (node3)
                        {
                            log("node2 tag:%d", node3->getTag());
                            log("node2 name:%s", node3->getName().c_str());
                        }
                        it3++;
                    }
                }
                it2++;
            }
        }
        it++;
    }
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
