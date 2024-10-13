# Corrigindo a adição de patches na legenda e o eixo do gráfico
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches

# Definindo os períodos e tempos de execução das tarefas
tasks = {
    'T1': {'period': 4, 'execution': 1, 'color': 'red'},
    'T2': {'period': 5, 'execution': 2, 'color': 'blue'},
    'T3': {'period': 8, 'execution': 3, 'color': 'green'}
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
    
    # Distribuir as execuções ao longo do tempo
    for start_time in range(0, time_horizon, period):
        ax.broken_barh([(start_time, execution_time)], (10 * (i+1), 9), facecolors=(color))

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
