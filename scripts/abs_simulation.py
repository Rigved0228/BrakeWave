import time
import numpy as np
import pandas as pd
import plotly.graph_objs as go
from plotly.subplots import make_subplots
import plotly.io as pio
import os

# Correct file path relative to the scripts folder
file_path = os.path.join('..', 'build', 'simulation_data.csv')


def simulate_real_time_data():
    # Simulate real-time data
    num_samples = 100
    time_data = np.linspace(0, 10, num_samples)
    vehicle_speed = 30.0 * (1.0 - time_data / max(time_data))
    wheel_speed = vehicle_speed * (1 - 0.1 * np.random.rand(num_samples))
    slip_ratio = (vehicle_speed - wheel_speed) / vehicle_speed
    brake_force = np.random.rand(num_samples) * 100

    return pd.DataFrame({
        'Time': time_data,
        'VehicleSpeed': vehicle_speed,
        'WheelSpeed': wheel_speed,
        'SlipRatio': slip_ratio,
        'BrakeForce': brake_force
    })


def plot_real_time_data():
    # Create subplots
    fig = make_subplots(rows=3, cols=1, shared_xaxes=True,
                        vertical_spacing=0.1)

    # Initial empty traces
    vehicle_speed_trace = go.Scatter(
        x=[], y=[], mode='lines', name='Vehicle Speed')
    wheel_speed_trace = go.Scatter(
        x=[], y=[], mode='lines', name='Wheel Speed')
    slip_ratio_trace = go.Scatter(x=[], y=[], mode='lines', name='Slip Ratio')
    brake_force_trace = go.Scatter(
        x=[], y=[], mode='lines', name='Brake Force')

    # Add traces to subplots
    fig.add_trace(vehicle_speed_trace, row=1, col=1)
    fig.add_trace(wheel_speed_trace, row=1, col=1)
    fig.add_trace(slip_ratio_trace, row=2, col=1)
    fig.add_trace(brake_force_trace, row=3, col=1)

    # Update layout
    fig.update_layout(height=800, width=1000,
                      title_text="Real-Time ABS Simulation Data", showlegend=True)
    fig.update_xaxes(title_text="Time (s)", row=3, col=1)
    fig.update_yaxes(title_text="Speed (m/s)", row=1, col=1)
    fig.update_yaxes(title_text="Slip Ratio", row=2, col=1)
    fig.update_yaxes(title_text="Brake Force", row=3, col=1)

    # Show the figure in a browser once
    pio.show(fig)

    # Simulate real-time updates
    while True:
        data = simulate_real_time_data()

        # Update traces with new data
        fig.update_traces(x=[data['Time']], y=[
                          data['VehicleSpeed']], selector=dict(name='Vehicle Speed'))
        fig.update_traces(x=[data['Time']], y=[
                          data['WheelSpeed']], selector=dict(name='Wheel Speed'))
        fig.update_traces(x=[data['Time']], y=[
                          data['SlipRatio']], selector=dict(name='Slip Ratio'))
        fig.update_traces(x=[data['Time']], y=[
                          data['BrakeForce']], selector=dict(name='Brake Force'))

        # Use plotly's update method to refresh the plot without reopening the browser
        pio.show(fig, auto_open=False)

        # Pause for a second to simulate real-time update
        time.sleep(1)


if __name__ == "__main__":
    plot_real_time_data()
