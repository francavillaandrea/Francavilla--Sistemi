import random
import threading
from threading import Thread
from time import sleep
from clinic import Patient, Secretary, Doctor

random_names = ["Alice", "Bob", "Charlie", "Diana", "Eve", "Frank", "Grace", "Heidi", "Ivan", "Judy"]

def new_patient():
    """Simulate the arrival of a new patient at the clinic."""
    patient = Patient(random.choice(random_names))
    print(f"New patient {patient} arrived at the clinic.")
    return patient

def secretary_work(secretary):
    """Simulate the work of a secretary at the clinic."""
    while True:
        patient = new_patient()
        secretary.add_patient_to_queue(patient)
        sleep(random.randint(1, 5))

def doctor_work(doctor):
    """Simulate the work of a doctor at the clinic."""
    while True:
        doctor.consult_patient()
        sleep(random.randint(1, 5))

def main():
    print("Welcome to the medicine clinic!")

    patients: list[Patient] = []
    clinic_lock = threading.Lock()

    secretaries = [
        Secretary("Sophie", patients, clinic_lock),
        Secretary("Liam", patients, clinic_lock),
        Secretary("Olivia", patients, clinic_lock),
        Secretary("Noah", patients, clinic_lock),
    ]

    doctors = [
        Doctor("Dr. Smith", patients, clinic_lock),
        Doctor("Dr. Johnson", patients, clinic_lock),
        Doctor("Dr. Williams", patients, clinic_lock),
        Doctor("Dr. Brown", patients, clinic_lock),
        Doctor("Dr. Jones", patients, clinic_lock),
        Doctor("Dr. Miller", patients, clinic_lock),
    ]

    threads = []

    for sec in secretaries:
        t = Thread(target=secretary_work, args=(sec,))
        threads.append(t)
        t.start()

    for doc in doctors:
        t = Thread(target=doctor_work, args=(doc,))
        threads.append(t)
        t.start()

    for t in threads:
        t.join()

if __name__ == "__main__":
    main()
