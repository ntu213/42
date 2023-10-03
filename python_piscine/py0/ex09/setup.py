
import setuptools as st

st.setup(
    name='ft_package',
    version='0.0.1',
    author='vgiraudo',
    author_email='vgiraudo@42perpignan,fr',
    description='Useless Package',
    packages=st.find_packages(),
    classifiers=[
        'Programming Language :: Python :: 3',
        'License :: OSI Approved :: MIT License',
        'Operating System :: OS Independent',
    ],
    python_requires='>=3.6',
)

# python setup.py bdist_wheel sdist
# pip3 install ./dist/ft_package-0.0.1.tar.gz
# ou pip3 install ./dist/ft_package-0.0.1-py3-none-any.whl
