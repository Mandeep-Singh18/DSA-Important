 Short Approach: Asteroid Collision Using Stack
          Use a stack to simulate asteroid collisions.
          Positive values (a > 0) move right → push to stack.
          Negative values (a < 0) move left:
          While top of stack is a smaller right-moving asteroid (> 0 and < -a), pop it.
          If stack is empty or top is also moving left (< 0), push current asteroid (no collision).
          If top is equal in size and opposite sign (top == -a), both explode → pop.
          Finally, return all remaining asteroids in the stack (from bottom to top).


vector<int> asteroidCollision(vector<int>& asteroids) {
    std::stack<int> stack;  // Stack to simulate asteroid collisions

    for (int a : asteroids) {
        if (a > 0) {
            stack.push(a);  // Right-moving asteroid → just push
        } else {
            // While top is right-moving and smaller → it explodes
            while (!stack.empty() && stack.top() > 0 && stack.top() < -a) {
                stack.pop();
            }

            // If stack is empty or top is also left-moving → no collision
            if (stack.empty() || stack.top() < 0) {
                stack.push(a);
            }

            // If same size but opposite direction → both explode
            else if (!stack.empty() && stack.top() == -a) {
                stack.pop();
            }
        }
    }

    // Transfer result from stack to vector in reverse order
    std::vector<int> res(stack.size());
    int i = stack.size() - 1;

    while (!stack.empty()) {
        res[i--] = stack.top();
        stack.pop();
    }

    return res;  // Return surviving asteroids
}
