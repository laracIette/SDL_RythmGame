SDL:
	g++ \
	\
	-Iinc/SDL-release-2.24.0/include \
	-Iinc/SDL2_image-2.6.2 \
	-Iinc/SDL2_mixer-2.6.2/include \
	-Iinc/SDL2_ttf-2.20.1 \
	-Iinc \
	\
	-o build/prog \
	-fpic \
	\
	src/main.cpp \
	\
	RythmGame.Framework/File/File.cpp \
	RythmGame.Framework/Window/Window.cpp \
	\
	RythmGame.Game/Exit/Window/Window.cpp \
	RythmGame.Game/FPS/Window/Window.cpp \
	\
	RythmGame.Game/Gameplay/Accuracy/Accuracy.cpp \
	RythmGame.Game/Gameplay/Combo/Combo.cpp \
	RythmGame.Game/Gameplay/Map/Map.cpp \
	RythmGame.Game/Gameplay/Player/Player.cpp \
	RythmGame.Game/Gameplay/Score/Score.cpp \
	\
	RythmGame.Game/Menu/MapSelection/Screen/Screen.cpp \
	RythmGame.Game/Menu/MapSelection/SongTile/SongTile.cpp \
	RythmGame.Game/Menu/StartScreen/Screen/Screen.cpp \
	\
	RythmGame.Game/Run/Run.cpp \
	\
	RythmGame.Game/Settings/Window/Window.cpp \
	\
	RythmGame.Game/Song/Song.cpp \
	\
	RythmGame.Graphics/Animation/Animation.cpp \
	RythmGame.Graphics/BoxRoundedCorners/BoxRoundedCorners.cpp \
	RythmGame.Graphics/Image/Image.cpp \
	\
	RythmGame.Graphics/Settings/CheckBox/CheckBox.cpp \
	RythmGame.Graphics/Settings/OptionsBox/OptionsBox.cpp \
	RythmGame.Graphics/Settings/SliderBox/SliderBox.cpp \
	\
	RythmGame.Graphics/RenderQueue/RenderQueue.cpp \
	RythmGame.Graphics/Text/Text.cpp \
	RythmGame.Graphics/TextTTF/TextTTF.cpp \
	RythmGame.Graphics/TextureManager/TextureManager.cpp \
	\
	RythmGame.Sound/HitSound/HitSound.cpp \
	RythmGame.Sound/HitSoundManager/HitSoundManager.cpp \
	RythmGame.Sound/Music/Music.cpp \
	\
	-lSDL2main \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_mixer \
	-lSDL2_ttf

.PHONY: test clean

test: SDL
	build/prog

clean:
	rm -f SDL