import os
import shutil

from pymavlink.generator.mavgen import mavgen, Opts


def clear_dir(output_dir: str):
    ignorable_items = [".git", "message_definitions", "readme.md", "generate.py"]
    if os.path.exists(output_dir):
        for item in os.listdir(output_dir):
            if item not in ignorable_items:
                item_path = os.path.join(output_dir, item)
                if os.path.isdir(item_path):
                    shutil.rmtree(item_path)
                else:
                    os.remove(item_path)


def main():
    output_dir = os.path.dirname(__file__)

    opts = Opts(
        output=output_dir,
        wire_protocol="2.0",
        language="c",
        validate=True,
    )

    args = [
        os.path.join(output_dir, "message_definitions", "all.xml"),
        os.path.join(output_dir, "message_definitions", "common.xml"),
    ]

    clear_dir(output_dir)
    mavgen(opts, args)


if __name__ == "__main__":
    main()
