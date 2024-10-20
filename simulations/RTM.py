import matplotlib.pyplot as plt
import matplotlib.patches as mpatches

# Definindo os períodos e tempos de execução das tarefas
tasks = {
    'T1': {'period': 4, 'execution': 1, 'color': 'red', 'start_time': 0},  # T1 começa no tempo 0
    'T2': {'period': 5, 'execution': 2, 'color': 'blue', 'start_time': 2},  # T2 começa no tempo 0
    'T3': {'period': 8, 'execution': 3, 'color': 'green', 'start_time': 3}  # T3 começa no tempo 0
}

# Definindo o horizonte de tempo para o gráfico
time_horizon = 16

# Criação do gráfico
fig, ax = plt.subplots(figsize=(10, 5))

# Adicionando tarefas ao gráfico com o agendamento RMS
for i, (task_name, task_info) in enumerate(tasks.items()):
    period = task_info['period']
    execution_time = task_info['execution']
    color = task_info['color']
    start_time = task_info['start_time']
    
    # Distribuir as execuções ao longo do tempo, de acordo com o período
    current_time = start_time  # cada tarefa inicia no seu próprio tempo de início
    while current_time < time_horizon:
        ax.broken_barh([(current_time, execution_time)], (10 * (i+1), 9), facecolors=(color))
        current_time += period  # a próxima execução ocorre no próximo período

# Configurações do gráfico
ax.set_ylim(5, 40)
ax.set_xlim(0, time_horizon)
ax.set_xlabel('Tempo')
ax.set_yticks([15, 25, 35])
ax.set_yticklabels(['T1', 'T2', 'T3'])
ax.grid(True)

# Legenda
legend_patches = [mpatches.Patch(color=task['color'], label=task_name) for task_name, task in tasks.items()]
ax.legend(handles=legend_patches, loc='upper right')

# Título
plt.title('Gráfico de Escalonamento (Scheduling) - Rate Monotonic Scheduling')

# Exibir o gráfico
plt.show()
