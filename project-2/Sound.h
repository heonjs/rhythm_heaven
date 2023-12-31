#pragma once
#include "JSHResource.h"

namespace JSH
{
    class Sound : public JSHResource
    {
    public:
		virtual HRESULT Load(const wstring& path) override;
		bool LoadWavFile(const wstring& path);
		void Play(bool loop);
		void Stop(bool reset);
		void SetPosition(float position, bool loop);
		void SetVolume(float volume);
		int GetDecibel(float volume);

	private:
		LPDIRECTSOUNDBUFFER mSoundBuffer;
		DSBUFFERDESC mBufferDesc;
		int mVolume;
    };
}