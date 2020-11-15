#pragma once
#include "ItsEffingRaw.h"
#include "EffingDonkey.h"
namespace ARP {
	namespace HellsKitchen {
		class AnEffingRawDonkey {
		public:
			AnEffingRawDonkey(ItsEffingRaw raw, EffingDonkey donkey);
			ItsEffingRaw raw;
			EffingDonkey donkey;
		};
	}
}