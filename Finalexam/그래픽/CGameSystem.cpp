#include"CGameSystem.h"
CGameSystem::CGameSystem() {
	m_pIntro = new CIntro();
	m_bIntro = true;


}
CGameSystem::~CGameSystem() {
	if (m_pIntro)
		delete m_pIntro;
}

void CGameSystem::SpecialKey(const int key , const int x, const int y ) {
	
}
void CGameSystem::GetKey(const unsigned char key, const int x, const int y) {

}
void CGameSystem::MouseButton(const int, const int, const int, const int) {

}
void CGameSystem::MouseMotion(const int, const int) {

}
void CGameSystem::Update() {

}
void CGameSystem::ChangeSize(int w, int h) {

}
void CGameSystem::Render() {

}