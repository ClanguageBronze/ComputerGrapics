#include"Character.h"

void Character::Init() {
	m_bMove = false;//이동가능 여부
	speed = 10;
	direction = 0;
	x_angle = 0.0;
	z_angle = 0.0;
	xPos = 0.0;
	yPos = 0.0;
	hp = 100.0;
	gage = 0.0;
	Start_Z = 0.0;
	Dead = false;
	memset(m_mtxlocal,0, sizeof(m_mtxlocal));
	m_mtxlocal[0] = m_mtxlocal[5] = m_mtxlocal[10] = m_mtxlocal[15] = 1;
	memset(m_mtxlocalt, 0, sizeof(m_mtxlocalt));
	m_mtxlocalt[0] = m_mtxlocalt[5] = m_mtxlocalt[10] = m_mtxlocalt[15] = 1;
	body_obj = gluNewQuadric();
	Front_obj = gluNewQuadric();
	Tail_obj = gluNewQuadric();
	Glass_part = gluNewQuadric();
	Mouth_obj = gluNewQuadric();
	for (int i = 0; i < 2; i++) {
		Engine_obj[i] = gluNewQuadric();
		gluQuadricDrawStyle(Engine_obj[i], GLU_FILL);
		gluQuadricNormals(Engine_obj[i], GLU_SMOOTH);


		Equipment_other[i] = gluNewQuadric();
		gluQuadricDrawStyle(Equipment_other[i], GLU_FILL);
		gluQuadricNormals(Equipment_other[i], GLU_SMOOTH);
	}
	for (int i = 0; i < 4; i++) {




		Tail_wing_part[i] = gluNewQuadric();
		gluQuadricDrawStyle(Tail_wing_part[i], GLU_FILL);
		gluQuadricNormals(Tail_wing_part[i], GLU_SMOOTH);

		Wing_part[i] = gluNewQuadric();
		gluQuadricDrawStyle(Wing_part[i], GLU_FILL);
		gluQuadricNormals(Wing_part[i], GLU_SMOOTH);

		Wing_other_part[i] = gluNewQuadric();
		gluQuadricDrawStyle(Wing_other_part[i], GLU_FILL);
		gluQuadricNormals(Wing_other_part[i], GLU_SMOOTH);
	}
	for (int i = 0; i < 6; i++) {
		Equipment[i] = gluNewQuadric();
		gluQuadricDrawStyle(Equipment[i], GLU_FILL);
		gluQuadricNormals(Equipment[i], GLU_SMOOTH);
	}

	for (int i = 0; i < 8; i++) {
		Tail_wing_otherpart[i] = gluNewQuadric();
		gluQuadricDrawStyle(Tail_wing_otherpart[i], GLU_FILL);
		gluQuadricNormals(Tail_wing_otherpart[i], GLU_SMOOTH);
	}

	gluQuadricDrawStyle(body_obj, GLU_FILL);
	gluQuadricNormals(body_obj, GLU_SMOOTH);
	gluQuadricDrawStyle(Front_obj, GLU_FILL);
	gluQuadricNormals(Front_obj, GLU_SMOOTH);
	gluQuadricDrawStyle(Tail_obj, GLU_FILL);
	gluQuadricNormals(Tail_obj, GLU_SMOOTH);
	gluQuadricDrawStyle(Mouth_obj, GLU_FILL);
	gluQuadricNormals(Mouth_obj, GLU_SMOOTH);
	gluQuadricDrawStyle(Glass_part, GLU_FILL);
	gluQuadricNormals(Glass_part, GLU_SMOOTH);
}
void Character::Render() {
	glPushMatrix();
	glTranslatef(0.0, 10.0, 0.0);
	//glRotatef(180, 0, 1, 0);
	glMultMatrixf(m_mtxlocalt);
	glMultMatrixf(m_mtxlocal);



	glPushMatrix(); {//전체 


		glScalef(0.5f, 0.5f, 1.0f);
		

		

		//몸통
		glColor3f(0.2117f, 0.2705f, 0.3098f);
		gluCylinder(body_obj, 20, 30, 50, 5, 8);
		gluDisk(Tail_obj, 0.0, 20, 5, 3);

		glPushMatrix(); {//앞부분
			glTranslatef(0.0, 0.0, 50.0);
			gluCylinder(Front_obj, 30, 15, 15, 5, 8);
			glPushMatrix(); {
				glColor3f(0.2627f, 0.8549f, 0.9254f);//67,218,236
				glTranslatef(0, 25, 0.0);

				gluSphere(Glass_part, 10, 20, 20);
			}glPopMatrix();
		}glPopMatrix();
		glColor3f(0.2117f, 0.2705f, 0.3098f);
		glPushMatrix(); {//앞부분
			glTranslatef(0.0, 0.0, 65.0);
			gluCylinder(Mouth_obj, 15, 0.0, 20, 5, 8);
		}glPopMatrix();
		glPushMatrix(); {
			//출력부분.
			glTranslatef(10, 0, -3);
			gluCylinder(Engine_obj[0], 10, 6, 3, 6, 6);
		}glPopMatrix();
		glPushMatrix();
		glTranslatef(-10, 0, -3);
		gluCylinder(Engine_obj[1], 10, 6, 3, 6, 6);
		glPopMatrix();
		glPushMatrix();
		glColor3f(0.2117f, 0.2705f, 0.3098f);
		glPushMatrix();

		glTranslatef(50, 0, 25);
		//glRotatef(-36.0, 0.0, 0.0, 1.0);
		glScalef(1.0, 0.1, 1.0);
		glRotatef(10, 0.0, 1.0, 0.0);
		gluCylinder(Wing_part[0], 60, 60, 10, 4, 20);
		gluDisk(Wing_other_part[0], 0.0, 60, 4, 3);
		glPushMatrix();
		glScalef(1.0, 10.0, 1.0);
		glTranslatef(0, 0, 10);
		glScalef(1.0, 0.1, 1.0);
		gluDisk(Wing_other_part[1], 0.0, 60, 4, 3);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();

		glTranslatef(-50, 0, 25);
		glRotatef(-10, 0.0, 1.0, 0.0);
		glScalef(1.0, 0.1, 1.0);
		gluCylinder(Wing_part[1], 60, 60, 10, 4, 20);
		gluDisk(Wing_other_part[2], 0.0, 60, 4, 3);
		glPushMatrix();
		glScalef(1.0, 10.0, 1.0);
		glTranslatef(0, 0, 10);
		glScalef(1.0, 0.1, 1.0);
		gluDisk(Wing_other_part[3], 0.0, 60, 4, 3);
		glPopMatrix();
		glPopMatrix();

		//꼬리부분
		glPushMatrix();
		glTranslatef(30.0, 0.0, 0.0);
		glRotatef(10, 0.0, 1.0, 0.0);
		glScalef(1.0, 0.1, 1.0);
		gluCylinder(Tail_wing_part[0], 30, 30, 8, 4, 20);
		gluDisk(Tail_wing_otherpart[0], 0.0, 30, 4, 3);
		glPushMatrix();
		glScalef(1.0, 10.0, 1.0);
		glTranslatef(0, 0, 8);
		glScalef(1.0, 0.1, 1.0);
		gluDisk(Tail_wing_otherpart[1], 0.0, 30, 4, 3);
		glPopMatrix();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-30.0, 0.0, 0.0);
		glRotatef(-10, 0.0, 1.0, 0.0);
		glScalef(1.0, 0.1, 1.0);
		gluCylinder(Tail_wing_part[1], 30, 30, 8, 4, 20);
		gluDisk(Tail_wing_otherpart[2], 0.0, 30, 4, 3);
		glPushMatrix();
		glScalef(1.0, 10.0, 1.0);
		glTranslatef(0, 0, 8);
		glScalef(1.0, 0.1, 1.0);
		gluDisk(Tail_wing_otherpart[3], 0.0, 30, 4, 3);
		glPopMatrix();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(20.0, 8.0, 5.0);
		glRotatef(60, 0.0, 0.0, 1.0);
		glScalef(1.0, 0.1, 1.0);
		gluCylinder(Tail_wing_part[2], 30, 30, 6, 4, 20);
		gluDisk(Tail_wing_otherpart[4], 0.0, 30, 4, 3);
		glPushMatrix();
		glScalef(1.0, 10.0, 1.0);
		glTranslatef(0, 0, 6);
		glScalef(1.0, 0.1, 1.0);
		gluDisk(Tail_wing_otherpart[5], 0.0, 30, 4, 3);
		glPopMatrix();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-20.0, 8.0, 5.0);
		glRotatef(-60, 0.0, 0.0, 1.0);
		glScalef(1.0, 0.1, 1.0);

		gluCylinder(Tail_wing_part[2], 30, 30, 6, 4, 20);
		gluDisk(Tail_wing_otherpart[6], 0.0, 30, 4, 3);
		glPushMatrix();
		glScalef(1.0, 10.0, 1.0);
		glTranslatef(0, 0, 6);
		glScalef(1.0, 0.1, 1.0);
		gluDisk(Tail_wing_otherpart[7], 0.0, 30, 4, 3);
		glPopMatrix();
		glPopMatrix();


		//무기
		glPushMatrix();
		glTranslatef(35, -10, 25);
		gluCylinder(Equipment[0], 6, 6, 10, 20, 8);
		gluDisk(Equipment_other[0], 0, 6, 20, 3);
		glPushMatrix();



		glTranslatef(4, 0.2, 6);
		gluCylinder(Equipment[2], 2, 2, 10, 20, 8);

		glPopMatrix();

		glPushMatrix();
		glTranslatef(-2, 0.2, 6);
		gluCylinder(Equipment[3], 2, 2, 10, 20, 8);

		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-35, -10, 25);
		gluCylinder(Equipment[1], 6, 6, 10, 20, 8);
		gluDisk(Equipment_other[1], 0, 6, 20, 3);
		glPushMatrix();



		glTranslatef(-4, 0.2, 6);
		gluCylinder(Equipment[4], 2, 2, 10, 20, 8);

		glPopMatrix();

		glPushMatrix();
		glTranslatef(2, 0.2, 6);
		gluCylinder(Equipment[5], 2, 2, 10, 20, 8);

		glPopMatrix();


		glPopMatrix();



	}glPopMatrix();



	glPopMatrix();
}
void Character::  Move() {
	Start_Z += speed;
	if (Start_Z > START_DAY) {
		m_bMove = true;
	}
	glPushMatrix(); {
		glLoadIdentity();
		glTranslatef(0.0, 0.0, speed);
		glMultMatrixf(m_mtxlocalt);
		glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocalt);
	}glPopMatrix();
	if (Start_Z >= START_DAY-300 && Start_Z <= START_DAY) {
		glPushMatrix(); {
			glLoadIdentity();
			glTranslatef(0.0, speed - 7, 0.0);
			glMultMatrixf(m_mtxlocalt);
			glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocalt);
		}glPopMatrix();
		if (x_angle > -35) {
			glPushMatrix(); {
				x_angle -= 5;
				glLoadIdentity();
				glRotatef(-ANGLE, 1, 0, 0);
				glMultMatrixf(m_mtxlocal);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocal);
			}
			glPopMatrix();
		}
	}
	if (direction == 0) {
		if (x_angle > 0.0&&m_bMove) {
			x_angle -= 5;
			glPushMatrix(); {
				glLoadIdentity();
				glRotatef(-ANGLE, 1.0, 0.0, 0.0);
				glMultMatrixf(m_mtxlocal);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocal);
			}glPopMatrix();
		}
		if (x_angle < 0.0&&m_bMove) {
			x_angle += 5;
			glPushMatrix(); {
				glLoadIdentity();
				glRotatef(ANGLE, 1.0, 0.0, 0.0);
				glMultMatrixf(m_mtxlocal);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocal);
			}glPopMatrix();
		}
		if (z_angle >= 0.0&&m_bMove) {
			z_angle -= 5;
			glPushMatrix(); {
				glLoadIdentity();
				glRotatef(-ANGLE, 0.0, 0.0, 1.0);
				glMultMatrixf(m_mtxlocal);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocal);
			}glPopMatrix();
		}
		if (z_angle <= 0.0&&m_bMove) {
			z_angle += 5;
			glPushMatrix(); {
				glLoadIdentity();
				glRotatef(ANGLE, 0.0, 0.0, 1.0);
				glMultMatrixf(m_mtxlocal);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocal);
			}glPopMatrix();
		}
	}
	
	if (direction == 1)/*위*/ {
		if (yPos < 175) {
			yPos += speed-5;
			glPushMatrix(); {
				glLoadIdentity();
				glTranslatef(0, speed - 5, 0.0);
				glMultMatrixf(m_mtxlocalt);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocalt);
			}glPopMatrix();
		}
		if (x_angle >-45) {
			x_angle -= 5.0;
			glPushMatrix(); {
				glLoadIdentity();
				glRotatef(-ANGLE, 1.0, 0.0, 0.0);
				glMultMatrixf(m_mtxlocal);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocal);
			}glPopMatrix();
		}
	}
	//아래
	if (direction == 2) {
		if (yPos > -10) {
			yPos -= speed - 5;
			glPushMatrix(); {
				glLoadIdentity();
				glTranslatef(0, -speed + 5, 0.0);
				glMultMatrixf(m_mtxlocalt);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocalt);
			}glPopMatrix();
		}
		if (x_angle < 45) {
			x_angle += 5.0;
			glPushMatrix(); {
				glLoadIdentity();
				glRotatef(ANGLE, 1.0, 0.0, 0.0);
				glMultMatrixf(m_mtxlocal);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocal);
			}glPopMatrix();
		}
	}
	//ㅇ른
	if (direction == 3) {
		if (xPos < 250) {
			xPos += speed - 5;
			glPushMatrix(); {
				glLoadIdentity();
				glTranslatef(speed - 5, 0.0, 0.0);
				glMultMatrixf(m_mtxlocalt);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocalt);
			}glPopMatrix();
		}
		if (z_angle > -45) {
			z_angle -= 5.0;
			glPushMatrix(); {
				glLoadIdentity();
				glRotatef(-ANGLE, 0.0, 0.0, 1.0);
				glMultMatrixf(m_mtxlocal);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocal);
			}glPopMatrix();
		}
	}
	//왼
	if (direction == 4) {
		if (xPos > -250) {
			xPos += -speed+5;
			glPushMatrix(); {
				glLoadIdentity();
				glTranslatef(-speed + 5, 0.0, 0.0);
				glMultMatrixf(m_mtxlocalt);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocalt);
			}glPopMatrix();
		}
		if (z_angle< 45) {
			z_angle += 5.0;
			glPushMatrix(); {
				glLoadIdentity();
				glRotatef(ANGLE, 0.0, 0.0, 1.0);
				glMultMatrixf(m_mtxlocal);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocal);
			}glPopMatrix();
		}
	}
	

}
void Character::Getspecial(const int key, const int x, const int y) {
	if (m_bMove) {
		if (key == GLUT_KEY_RIGHT) {
			direction = 4;
		}
		if (key == GLUT_KEY_LEFT) {
			direction = 3;
		}
		if (key == GLUT_KEY_DOWN) {
			direction = 2;
		}
		if (key == GLUT_KEY_UP) {
			direction = 1;
		}
		if (key == NULL) {
			direction = 0;
		}
	}
}




void Character::Death() {
}