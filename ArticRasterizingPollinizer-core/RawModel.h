#pragma once

namespace ARP {
	namespace HellsKitchen {
		class RawModel {
		private:
			int vaoID;
			int vertexcount;
		public:
			RawModel(int vaoID, int vertexcount);
			int getvaoID() { return vaoID; }
			int getvertexcount() { return vertexcount; }
		};
	}
}