// thanks to RayDeeUx for helping fix the pause button :D
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;

struct VarPauseLayer : Modify<VarPauseLayer, PauseLayer> {
  void onVarSettings(CCObject *object) {
    geode::openSettingsPopup(Mod::get());
  }

  void customSetup() {
    PauseLayer::customSetup();

    auto settingsButtonSprite = CCSprite::create("button.png"_spr);
    settingsButtonSprite->setScale(.25f);
    if (auto betterPause = Loader::get()->getLoadedMod("tpdea.betterpause-Better")) {
      if (betterPause->getSettingValue<int64_t>("type-pause") == 1) settingsButtonSprite->setScale(.95f);
    }

    auto settingsBtn = CCMenuItemSpriteExtra::create(
      settingsButtonSprite, 
      this,
      menu_selector(VarPauseLayer::onVarSettings)
    );

    settingsBtn->setID("varmanager-settings-button"_spr);
    if (auto leftMenu = getChildByIDRecursive("left-button-menu")) {
      leftMenu->addChild(settingsBtn);
      leftMenu->updateLayout();
    }
  }
};
