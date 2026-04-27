import threading
class Patient:
    """A patient in the clinic."""

    name: str
    """The name of the patient."""

    def __init__(self, name):
        """Initialize a new patient with the given name."""
        self.name = name

    def __str__(self):
        """Return a string representation of the patient."""
        return f"Patient {self.name}"

class Doctor:
    """A doctor in the clinic."""

    name: str
    """The name of the doctor."""

    # TODO: Add other attributes here if needed
    patients: list[Patient]
    lock: threading.Lock

    def __init__(self, name: str, patients: list[Patient], lock: threading.Lock): # TODO: add other parameters here if needed
        """Initialize a new doctor with the given name and list of patients."""
        self.name = name
        self.patients = patients
        self.lock = lock

    def __str__(self):
        """Return a string representation of the doctor."""
        return f"Doctor {self.name}"

    def consult_patient(self):
        """Consult the next patient in the queue."""
        patient = None # TODO: Get the next patient from the queue here
        with self.lock:
            if len(self.patients) > 0:
                patient = self.patients.pop(0)
            if patient:
                print(f"{self} is consulting {patient}.")
            else:
                print(f"{self} finds no patients in queue.")
class Secretary:
    """A secretary in the clinic."""

    name: str
    """The name of the secretary."""

    # TODO: Add other attributes here if needed
    patients: list[Patient]
    lock: threading.Lock

    def __init__(self, name: str, patients: list[Patient], lock: threading.Lock): # TODO: add other parameters here if needed
        """Initialize a new secretary with the given name and list of patients."""
        self.name = name
        self.patients = patients
        self.lock = lock
    def __str__(self):
        """Return a string representation of the secretary."""
        return f"Secretary {self.name}"

    def add_patient_to_queue(self, patient : Patient):
        """Add a patient to the queue."""
        with self.lock:
            self.patients.append(patient)
            # TODO: Add the patient to the queue here
            print(f"{self} is adding {patient} to the queue. Total: {len(self.patients)}")


