#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include <unistd.h>
#include <cstring>

bool DoConversion(istream& in, ostream& out, bool strip);

void usage(char* argv[])
{
    cout << "Usage:" << endl <<
            argv[0] << " -i input -o output [-n]" << endl;

    cout << "i - specify input file" << endl <<
            "o - specify output file" << endl <<
            "n - don't strip names from module" << endl;
}

int main(int argc, char* argv[])
{
    char* inFile = NULL;
    char* outFile = NULL;
    bool stripText = true;
    int opt, optind = 1;
    // check our arguments
    while((opt=getopt(argc, argv, "i:o:n")) != -1)
    {
        switch(opt)
        {
            case 'i':
                ++optind;
                inFile = strdup(argv[optind]);
                cout << "Using input file " << inFile << endl;
            break;

            case 'o':
                ++optind;
                outFile = strdup(argv[optind]);
                cout << "Using output file " << outFile << endl;
            break;

            case 'n':
                stripText = false;
                cout << "Not stripping names from module" << endl;
            break;

            case '?':
                usage(argv);
                return 0;
            break;
        }

        ++optind;
    }

    if(!inFile || !outFile)
    {
        cerr << "Input and output files are required." << endl;
        usage(argv);
        return 0;
    }

    ifstream isFile(inFile, ios::in | ios::binary);
    if(isFile.fail())
    {
        cerr << "Could not open input file." << endl;
        return 0;
    }
    else
    {
        // don't throw exceptions
        isFile.exceptions(ios::goodbit);
    }

    ofstream osFile;
    osFile.open(outFile, ios::out | ios::trunc | ios::binary);
    if(osFile.fail())
    {
        cerr << "Could not create output file." << endl;
        return 0;
    }
    else
    {
        osFile.exceptions(ios::goodbit);
    }

    if(DoConversion(isFile, osFile, stripText))
    {
        isFile.close();
        osFile.close();
        cout << "Success!" << endl;
    }
    else
    {
        cerr << "Failure..." << endl;
    }

    return 0;
}

struct sample_s
{
    char name[23];
    unsigned long length;
    char finetune;
    unsigned char volume;
    unsigned long loopstart;
    unsigned long looplength;
    char* audiodata;
};

struct note_s
{
    int note:11;
    unsigned char number:5;
    unsigned char effect;
    unsigned char eparam;
};

const int nNotes = 12 * 3;
unsigned short periods[nNotes] =
{
	856,808,762,720,678,640,604,570,538,508,480,453, // C-1 to B-1
	428,404,381,360,339,320,302,285,269,254,240,226, // C-2 to B-2
	214,202,190,180,170,160,151,143,135,127,120,113  // C-3 to B-3
};

#pragma pack(1)
struct sections_s
{
    unsigned char numinsts;
    unsigned short offsetinsts;
    unsigned char numorders;
    unsigned short offsetorders;
    unsigned char numpatterns;
    unsigned short offsetpatterns;
    unsigned char numsamples;
    unsigned short offsetsamples;
    unsigned char numnames;
    unsigned short offsetnames;
};

bool DoConversion(istream& in, ostream& out, bool strip)
{
    char signature[] = "SIGN";
    char title[21];
    vector<sample_s> samples;
    int cutoffSample = 0;
    int numOrders = 0;
    vector<int> orders;
    int numPatterns = 0;
    unsigned long numNotes = 0;
    unsigned long patternSize = 0;
    char* patterns = NULL;
    struct note_s* note = NULL;
    struct sections_s sections = {0,0,0,0,0,0,0,0,0,0};

    if(in.fail() || out.fail())
    {
        return false;
    }

{ // reader
    // Verify the module
    in.seekg(1080); // Sig at offset 1080
    in.read(signature, 4);

    if(!strcmp(signature, "M.K."))
    {
        cout << "Input module verified to be good, 4 channels." << endl;
    }
    else
    {
        cout << "Sorry, bad file. Must be a 4 channel module." << endl;
        return false;
    }

    // Go back to start
    in.seekg(0);

    // if something's wrong
    if(in.fail())
    {
        // leave
        return false;
    }

    // Get the title;
    in.read(title, 20);
    title[20] = '\0';

    cout << "Song title: \"" << title << "\"" << endl;

    // todo: load rest of module
    for(int i = 0; i < 31; ++i)
    {
        struct sample_s smp;
        unsigned char tmp[2];

        in.read(smp.name, 22);
        smp.name[22] = '\0';

        in.read((char*)tmp, 2);
        smp.length = (tmp[0] * 0x100 + tmp[1]) << 1;
        smp.length = (smp.length < 4)?(0):(smp.length);

        smp.finetune = in.get();
        smp.finetune = (smp.finetune>7)?(smp.finetune-16):(smp.finetune);

        smp.volume = in.get();

        in.read((char*)tmp, 2);
        smp.loopstart = (tmp[0] * 0x100 + tmp[1]) << 1;
        smp.loopstart = (smp.loopstart < 4)?(0):(smp.loopstart);

        in.read((char*)tmp, 2);
        smp.looplength = (tmp[0] * 0x100 + tmp[1]) << 1;
        smp.looplength = (smp.looplength < 4)?(0):(smp.looplength);

        smp.audiodata = NULL;

        if(smp.length)
        {
            cutoffSample = i+1;
        }

        cout << "Sample #" << i << ":" << endl;
        cout << "Name: \"" << smp.name << "\"" << endl;
        cout << "Length: " << smp.length << endl;
        cout << "Finetune: " << (int)smp.finetune << endl;
        cout << "Volume: " << (int)smp.volume << endl;
        cout << "Loopstart: " << smp.loopstart << endl;
        cout << "Looplength: " << smp.looplength << endl
             << endl;

        samples.push_back(smp);
    }

    // check for stream failure again
    if(in.fail())
    {
        return false;
    }

    numOrders = in.get();
    in.get();   // skip unused byte

    cout << "Number of orders: " << numOrders << endl;
    cout << "Orders: " << endl;

    for(int i = 0; i < 128; ++i)
    {
        int ord = in.get();
        if(ord > numPatterns)
        {
            numPatterns = ord;
        }

        cout << ord << " ";
        orders.push_back(ord);
    }
    cout << endl;

    cout << "Number of patterns: " << numPatterns+1 << endl;

    // skip module sig
    in.seekg(4, ios_base::cur);

    // load pattern data
    numNotes =  4 * 64 * (numPatterns+1); // channels * rows * numpatterns
    patternSize = numNotes * 4;          // numNote * 4 bytes pernote;
    patterns = new(nothrow) char[patternSize];
    if(!patterns)
    {
        return false;
    }
    in.read(patterns, patternSize);

    if(in.fail())
    {
        delete[] patterns;
        return false;
    }

    note = (struct note_s*)patterns;
    for(unsigned long n = 0; n < numNotes; ++n)
    {
        int period;
        struct note_s temp;
        unsigned char* part = (unsigned char*)note;

        temp.number = (part[0] & 0xf0) + (part[2] >> 4);
        period = ((part[0] & 0xf) << 8) + part[1];
        temp.effect = part[2] & 0xf;
        temp.eparam = part[3];

        temp.note = 0xFF;
        for(int p = 0; p < nNotes; p++)
        {
            static int prev = 0;
            int cur = periods[p];

            if(cur <= period)
            {
                if(((prev-period) < (period-cur)) && (p != 0))
                {
                    temp.note = p-1;
                }
                else
                {
                    temp.note = p;
                }
                break;
            }

            prev = cur;
        }

        memcpy(note, &temp, 4);
        ++note;
    }

    //the monster that is patterndata is done, now the sample audio
    for(int s = 0; s < 31; ++s)
    {
        struct sample_s& smp = samples[s];
        if(!smp.length)
        {
            continue;
        }

        smp.audiodata = new(nothrow) char[smp.length];
        in.read(smp.audiodata, smp.length);
    }

    if(in.fail())
    {
        return false;
    }

    cout << "End of reading, offset: " << in.tellg() << endl;
}

{ // writer
    // done reading! now onto writing.

    cout << "Now, conversion begins." << endl;

    // we will write to our customized format for playing with an AVR
    out.seekp(0);
    out.write("AVRM", 4); // write out our magic signature "AVRM" at beginning instead of stupid 1080

    // set up our sections
    sections.numinsts = cutoffSample;
    sections.numorders = numOrders;
    sections.numpatterns = numPatterns+1;
    sections.numsamples = sections.numinsts;

    if(strip)
    {
        sections.numnames = 0;
    }
    else
    {
        sections.numnames = cutoffSample + 1; // the sample names + the title
    }

    // write our sections structure, minus offsets we will get later
    out.write((char*)&sections, sizeof(struct sections_s));

    // we are putting the instruments here so get the offset
    sections.offsetinsts = out.tellp();
    unsigned short tmp;
    for(int i = 0; i < cutoffSample; ++i)
    {
        struct sample_s& smp = samples[i];

        tmp = smp.length>>1;
        out.write((char*)&tmp, 2);

        out.put(smp.finetune);
        out.put(smp.volume);

        tmp = smp.loopstart>>1;
        out.write((char*)&tmp, 2);

        tmp = smp.looplength>>1;
        out.write((char*)&tmp, 2);
    }

    // we are putting the orders here so get the offset
    sections.offsetorders = out.tellp();
    for(int i = 0; i < numOrders; ++i)
    {
        out.put(orders[i]);
    }

    orders.clear();

    // we are putting the patterns here so get the offset
    sections.offsetpatterns = out.tellp();
    note = (struct note_s*)patterns;
    for(unsigned long n = 0; n < numNotes; ++n)
    {
        unsigned char part[3];

        /** Pattern Packing Format **
         *  uses 3 bytes per note
         *     -00-     -01-     -02-
         *  |  BYTE  |  BYTE  |  BYTE  |
         *   AAAAAABB BBCCCCCX DDDDDDDD
         *
         *  NOTE NUMBER = AAAAAA
         *  EFFECT      = BBBB
         *  INST NUMBER = CCCCC
         *  EFFECT PARM = DDDDDDDD
         *  UNUSED      = X
         */

        part[0] = (((unsigned char)note->note) << 2) | (((unsigned char)note->effect)>>2);
        part[1] = (((((unsigned char)note->effect) & 0x03)<<6) | (((unsigned char)note->number)<<1)) & 0xFE;
        part[2] = (unsigned char)note->eparam;

        out.write((char*)part, 3);

        note++;
    }

    delete[] patterns;

    // we are putting the samples here so get the offset
    sections.offsetsamples = out.tellp();
    for(int i = 0; i < cutoffSample; ++i)
    {
        struct sample_s& smp = samples[i];

        if(!smp.length)
        {
            continue;
        }

        out.write(smp.audiodata, smp.length);

        delete[] smp.audiodata;
    }

    if(!strip)
    {
        sections.offsetnames = out.tellp();
        out.write(title,20);
        out.put('\0');out.put('\0'); // for 22 bytes.

        for(int n = 0; n < (sections.numnames-1); ++n)
        {
            out.write(samples[n].name, 22);
        }
    }

    samples.clear();


    out.seekp(4); // seek back to the section table
    // write our sections structure, this time with the offsets
    out.write((char*)&sections, sizeof(struct sections_s));

    //Done conversion
    cout << "Conversion done!" << endl;
}


    return true;

fail:

    return false;
}
