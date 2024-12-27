#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(PlayerManager, PlayerObject) {
	void update(float p0) {
		PlayerObject::update(p0);

		set_setting<float>("set_rotation", this->getRotation());

		this->setScaleX(get_setting<float>("set_scale_x"));
		this->setScaleY(get_setting<float>("set_scale_y"));
		this->setVisible(get_setting<bool>("set_visible"));
		this->setRotation(get_setting<float>("set_rotation"));
		this->togglePlatformerMode(get_setting<bool>("set_platformer"));
	}

	template <typename T>
	T get_setting(std::string setting) {
		return Mod::get()->getSettingValue<T>(setting);
	}

	template <typename T>
	void set_setting(std::string setting, T value) {
		Mod::get()->setSettingValue<T>(setting, value);
	}
};