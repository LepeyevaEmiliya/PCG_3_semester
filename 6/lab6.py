import pygame
from OpenGL.GL import *
from OpenGL.GLU import *

vertices = (
    (0.05, -0.375, -0.25),
    (0.05, 0.125, -0.25),
    (-0.25, 0.125, -0.25),
    (-0.25, -0.375, -0.25),
    (0.05, -0.375, 0.25),
    (0.05, 0.125, 0.25),
    (-0.25, -0.375, 0.25),
    (-0.25, 0.125, 0.25),

    (0.25, 0.375, -0.25),
    (0.25, 0.375, 0.25),
    (-0.25, 0.375, -0.25),
    (-0.25, 0.375, 0.25),

    (0.425, 0.375, -0.25),
    (0.425, 0.375, 0.25),
    (0.425, 0.125, -0.25),
    (0.425, 0.125, 0.25)
)



edges = (
    (0, 1),
    (2, 3),
    (3, 0),
    (6, 7),
    (6, 3),
    (6, 4),
    (4, 5),
    (0, 4),

    (2, 10),
    (11, 7),
    (11, 9),
    (10, 8),
    (11, 10),

    (8, 12),
    (9, 13),
    (1, 14),
    (5, 15),
    (13, 15),
    (12, 14),
    (14, 15),
    (12, 13)
)

rotation_speed = 15.0
scale_speed = 0.1
translate_speed = 0.1

scaling = [1.0, 1.0, 1.0]
translation = [0.0, 0.0, 0.0]
rotation = [0.0, 0.0, 0.0]


def draw_axes():
    glBegin(GL_LINES)
    glColor3f(1, 0, 0)  # X-axis: red
    glVertex3f(-1, 0, 0)
    glVertex3f(1, 0, 0)
    glColor3f(0, 1, 0)  # Y-axis: green
    glVertex3f(0, -1, 0)
    glVertex3f(0, 1, 0)
    glColor3f(0, 0, 1)  # Z-axis: blue
    glVertex3f(0, 0, -1)
    glVertex3f(0, 0, 1)
    glEnd()


def draw_projection_onto_plane(plane):
    glBegin(GL_LINES)
    glColor3f(1, 1, 1)  # Color for object projection: white
    for edge in edges:
        for vertex in edge:
            if plane == 'xy':
                glVertex3f(vertices[vertex][0], vertices[vertex][1], 0)
            elif plane == 'xz':
                glVertex3f(vertices[vertex][0], 0, vertices[vertex][2])
            elif plane == 'yz':
                glVertex3f(0, vertices[vertex][1], vertices[vertex][2])
    glEnd()


def draw_letter():
    glLineWidth(4)
    glBegin(GL_LINES)
    for edge in edges:
        for vertex in edge:
            glColor3fv((0, 0, 1))  # Color for object edges: blue
            glVertex3fv(vertices[vertex])
    glEnd()


def main():
    pygame.init()
    display = (800, 600)
    pygame.display.set_mode(display, pygame.DOUBLEBUF | pygame.OPENGL)
    pygame.display.set_caption("PyOpenGL")
    gluPerspective(45, (display[0] / display[1]), 0.1, 50.0)
    glTranslatef(0.0, 0.0, -5)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    glRotatef(rotation_speed, 0, 1, 0)
                    rotation[1] += rotation_speed
                elif event.key == pygame.K_RIGHT:
                    glRotatef(-rotation_speed, 0, 1, 0)
                    rotation[1] -= rotation_speed
                elif event.key == pygame.K_UP:
                    glRotatef(rotation_speed, 1, 0, 0)
                    rotation[0] += rotation_speed
                elif event.key == pygame.K_DOWN:
                    glRotatef(-rotation_speed, 1, 0, 0)
                    rotation[0] -= rotation_speed
                elif event.key == pygame.K_w:
                    translation[1] += translate_speed
                elif event.key == pygame.K_s:
                    translation[1] -= translate_speed
                elif event.key == pygame.K_a:
                    translation[0] -= translate_speed
                elif event.key == pygame.K_d:
                    translation[0] += translate_speed
                elif event.key == pygame.K_q:
                    translation[2] += translate_speed
                elif event.key == pygame.K_e:
                    translation[2] -= translate_speed
                elif event.key == pygame.K_z:
                    scaling[0] += scale_speed
                    scaling[1] += scale_speed
                    scaling[2] += scale_speed
                elif event.key == pygame.K_x:
                    scaling[0] -= scale_speed
                    scaling[1] -= scale_speed
                    scaling[2] -= scale_speed
                elif event.key == pygame.K_o:  # Toggle projection display
                    glMatrixMode(GL_PROJECTION)
                    glLoadIdentity()
                    if glIsEnabled(GL_DEPTH_TEST):
                        glDisable(GL_DEPTH_TEST)
                    else:
                        glEnable(GL_DEPTH_TEST)

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        glLoadIdentity()

        glTranslatef(*translation)
        glScalef(*scaling)
        glRotatef(rotation[0], 1, 0, 0)
        glRotatef(rotation[1], 0, 1, 0)

        draw_axes()  # Draw axes in 3D space
        draw_letter()  # Draw 3D object

        # Draw object projections onto coordinate planes
        glMatrixMode(GL_PROJECTION)
        glLoadIdentity()
        glDisable(GL_DEPTH_TEST)
        glOrtho(-1, 1, -1, 1, -1, 1)

        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()
        glTranslatef(-2, -2, 0)
        draw_projection_onto_plane('xy')

        glLoadIdentity()
        glTranslatef(2, -2, 0)
        draw_projection_onto_plane('xz')

        glLoadIdentity()
        glTranslatef(-2, 2, 0)
        draw_projection_onto_plane('yz')

        pygame.display.flip()
        pygame.time.wait(10)


if __name__ == "__main__":
    main()
