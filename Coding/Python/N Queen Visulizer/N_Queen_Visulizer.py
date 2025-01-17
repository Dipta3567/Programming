import pygame
import time
import sys

# Constants
N = 8  # Change this for different board sizes
CELL_SIZE = 60
WIDTH, HEIGHT = N * CELL_SIZE, N * CELL_SIZE
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)

# Initialize Pygame
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("N-Queen Visualizer")


def draw_board(board):
    screen.fill(WHITE)
    for row in range(N):
        for col in range(N):
            color = WHITE if (row + col) % 2 == 0 else BLACK
            pygame.draw.rect(screen, color, (col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE, CELL_SIZE))
            if board[row][col] == 1:
                pygame.draw.circle(screen, RED, (col * CELL_SIZE + CELL_SIZE // 2, row * CELL_SIZE + CELL_SIZE // 2), CELL_SIZE // 3)
    pygame.display.flip()
    time.sleep(0.5)  # Delay for visualization


def is_safe(board, row, col):
    # Check column
    for i in range(row):
        if board[i][col] == 1:
            return False
    
    # Check upper diagonal (left)
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    
    # Check upper diagonal (right)
    for i, j in zip(range(row, -1, -1), range(col, N)):
        if board[i][j] == 1:
            return False
    
    return True


def solve_n_queen(board, row=0):
    if row >= N:
        return True
    
    for col in range(N):
        if is_safe(board, row, col):
            board[row][col] = 1
            draw_board(board)
            
            if solve_n_queen(board, row + 1):
                return True
            
            board[row][col] = 0  # Backtrack
            draw_board(board)
    
    return False


def main():
    board = [[0] * N for _ in range(N)]
    running = True
    
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        
        solve_n_queen(board)
        pygame.time.delay(2000)  # Delay to see the final board
        running = False
    
    pygame.quit()
    sys.exit()


if __name__ == "__main__":
    main()
