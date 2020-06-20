import json
import logging
import os
from pathlib import Path
import uuid


logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)


def acquire_identity():
    """
    Acquires a persistent, unique identifier for the current device.

    If a config file ~/.timecube.json exists, the identifier is attempted to be
    read from that file (property 'identifier').

    If the config file does not exist, a new identifier (UUID) is generated and
    stored in the config file.
    """

    config_file_name = '.timecube.json'
    config_file_path = os.path.join(Path.home(), config_file_name)

    if os.path.exists(config_file_path):
        logging.debug(f'found config file at {config_file_path}')
        data = {}
        with open(config_file_path, 'r') as f:
            payload = f.read()
            data = json.loads(payload)
        if 'identifier' in data:
            identifier = data['identifier']
            logging.debug(f'read identifier {identifier} from config file')
            return identifier
        else:
            logging.debug(f'identifier missing in config file')

    identifier = uuid.uuid4()
    logging.debug(f'generated new identifier {identifier}')
    data = {'identifier': str(identifier)}
    payload = json.dumps(data)
    with open(config_file_path, 'w') as f:
        f.write(payload)
    logging.debug(f'created config file at {config_file_path}')

    return identifier
