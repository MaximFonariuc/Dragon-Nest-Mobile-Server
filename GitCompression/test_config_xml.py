import glob
import os
import unittest
import xml.etree.ElementTree as ET


class ServerConfigXMLTests(unittest.TestCase):
    def test_all_server_config_files_are_well_formed(self):
        repository_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
        config_dir = os.path.join(repository_root, "exe", "conf")
        config_files = sorted(glob.glob(os.path.join(config_dir, "*.xml")))
        self.assertTrue(config_files, "No XML server configuration files found")

        for config_path in config_files:
            with self.subTest(config=os.path.basename(config_path)):
                ET.parse(config_path)


if __name__ == "__main__":
    unittest.main()
