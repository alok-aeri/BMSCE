import random

# Parameters
population_size = 30
generations = 50
mutation_rate = 0.1
selection_ratio = 0.5

# Gear teeth range
min_teeth = 10
max_teeth = 50

def fitness(a, b):
    # Calculate basic cost
    cost = abs(a * b - 100) + abs(a - b)
    ratio = a / b if b != 0 else 0
    
    # Penalty for gear ratios outside range
    if ratio < 0.8 or ratio > 1.25:
        cost += 50  # large penalty
    
    return cost

# Generate initial population
population = [(random.randint(min_teeth, max_teeth), random.randint(min_teeth, max_teeth)) for _ in range(population_size)]

for gen in range(generations):
    # Calculate fitness for all individuals
    pop_fitness = [(ind, fitness(*ind)) for ind in population]
    
    # Sort by fitness (minimize)
    pop_fitness.sort(key=lambda x: x[1])
    
    # Select top individuals
    survivors = pop_fitness[:int(selection_ratio * population_size)]
    selected = [ind for ind, fit in survivors]
    
    # Generate offspring by crossover (swap one gene)
    offspring = []
    while len(offspring) < population_size - len(selected):
        parent1, parent2 = random.sample(selected, 2)
        # Simple one-point crossover
        if random.random() < 0.5:
            child = (parent1[0], parent2[1])
        else:
            child = (parent2[0], parent1[1])
        offspring.append(child)
    
    # Mutation: randomly increment/decrement gene by 1 with mutation_rate
    for i in range(len(offspring)):
        if random.random() < mutation_rate:
            a, b = offspring[i]
            if random.random() < 0.5:
                a = min(max_teeth, max(min_teeth, a + random.choice([-1, 1])))
            else:
                b = min(max_teeth, max(min_teeth, b + random.choice([-1, 1])))
            offspring[i] = (a, b)
    
    # New population
    population = selected + offspring
    
    # Print best solution every 10 generations
    if gen % 10 == 0 or gen == generations - 1:
        best_individual, best_fit = min([(ind, fitness(*ind)) for ind in population], key=lambda x: x[1])
        print(f"Generation {gen}: Best teeth (a,b) = {best_individual} with fitness = {best_fit}")

# Final best solution
best_individual, best_fit = min([(ind, fitness(*ind)) for ind in population], key=lambda x: x[1])
print("\nFinal optimized gearbox teeth:")
print(f"a = {best_individual[0]}, b = {best_individual[1]}, Fitness = {best_fit}")
