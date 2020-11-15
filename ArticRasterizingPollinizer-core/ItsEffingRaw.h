#pragma once

namespace ARP {
	namespace HellsKitchen {
		class ItsEffingRaw {
		private:
			int vaoID;
			int vertexcount;
		public:
			ItsEffingRaw(int vaoID, int vertexcount);
			int getvaoID() { return vaoID; }
			int getvertexcount() { return vertexcount; }
		};
	}
}