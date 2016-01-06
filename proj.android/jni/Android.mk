LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)





LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
					   ../../Classes/Data/DataManager.cpp \
					   ../../Classes/Data/sqlite3.c \
					   ../../Classes/DragAndDrop/DraggableItem.cpp \
					   ../../Classes/DragAndDrop/DroppableItem.cpp \
					   ../../Classes/DragAndDrop/DroppablesManager.cpp \
					   ../../Classes/Gameplay/MashButton.cpp \
					   ../../Classes/Gameplay/GridCell.cpp \
					   ../../Classes/Gameplay/Grid.cpp \
					   ../../Classes/Gameplay/GameManager.cpp \
					   ../../Classes/Gameplay/User.cpp \
					   ../../Classes/Gameplay/MashButtonsManager.cpp \
							../../Classes/Gameplay/ButtonMasherEffects/ButtonMasherEffect.cpp \
							../../Classes/Gameplay/ButtonMasherEffects/ButtonMasherEffectsHandler.cpp \
							../../Classes/Gameplay/ButtonMasherEffects/ButtonMasherEffectCombo.cpp \
							../../Classes/Gameplay/ButtonMasherEffects/ButtonMasherEffectSpeeder.cpp \
							../../Classes/Gameplay/CoinsCollectors/CoinCollectedInformation.cpp \
							../../Classes/Gameplay/CoinsCollectors/CoinsCollector.cpp \
							../../Classes/Gameplay/CoinsCollectors/CollectorContactListener.cpp \
							../../Classes/Gameplay/CoinsCollectors/MovingLabel.cpp \
							../../Classes/Gameplay/PhysicsParticles/PhysicParticle.cpp \
							../../Classes/Gameplay/PhysicsParticles/PhysicParticleHandler.cpp \
					   ../../Classes/Scenes/MainMenuScene.cpp \
					   ../../Classes/Scenes/GameScene.cpp 
				 





LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,./prebuilt-mk)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
