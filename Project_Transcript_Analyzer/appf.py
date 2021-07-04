# How to run this program
# Install required Packages
# sudo python3 -m pip install pipenv pipenv-pipes
# pipenv install streamlit textblob spacy gensim neattext matplotlib wordcloud
# Once packages are installed
# Initialise Streanlit Virtual environment using pipes
# pipenv shell
# Run the program as streamlit run appf.py


# Core Packages
import streamlit as st
import spacy
import neattext as nt
from textblob import TextBlob
import neattext.functions as nfx
import matplotlib.pyplot as plt
import matplotlib
matplotlib.use("Agg")
from wordcloud import WordCloud

st.set_page_config(page_title="Transcript Analyzer")

# Function For Tokens and Lemma Analysis
@st.cache
def text_analyzer(my_text):
    nlp = spacy.load("en_core_web_sm")
    docx = nlp(my_text)
    allData = [('"Token":{},\n"Lemma":{}'.format(token.text,token.lemma_))for token in docx ]
    return allData

# Function For Wordcloud Plotting
def plot_wordcloud(my_text):
    mywordcloud = WordCloud().generate(my_text)
    # mywordcloud = mywordcloud.max_words(3)
    fig = plt.figure(figsize=(50,30))
    plt.imshow(mywordcloud,interpolation='bilinear')
    plt.axis('off')
    st.pyplot(fig)


def main():
    """Text Analysis with Streamlit and NLP"""
    st.title("Transcript Analyser with Streamlit and NLP")

    title_templ = """
    <div style="padding:8px;">
    </div>
    """
    st.markdown(title_templ, unsafe_allow_html=True)

    activity = ["Text Analysis", "About"]
    choice = st.sidebar.radio("Menu",activity)

    if choice == "Text Analysis":
        st.subheader("Text Analysis")
        st.write("")
        st.write("")

        raw_text = st.text_area("Enter your plain text here", height=300)
        customText = ['agent', 'customer', 'cosmo', 'agent-freehand', 'freehand', '/', '::', 'british', 'british gas', 'chat', 'engagement']
        final_processed_text = ''

        if st.button("Analyze"):
            col1, col2 = st.beta_columns(2)
            blob = TextBlob(raw_text)
            st.write("")

            st.info("Basic Analysis")
            col1, col2 = st.beta_columns(2)

            with col1:
                with st.beta_expander("Basic Info"):
                    st.success("Text Stats")
                    word_desc = nt.TextFrame(raw_text).word_stats()
                    result_desc = {"Length of Text":word_desc['Length of Text'],
                                    "Num of Vowels":word_desc['Num of Vowels'],
                                    "Num of Consonants":word_desc['Num of Consonants'],
                                    "Num of Stopwords":word_desc['Num of Stopwords']}
                    st.write(result_desc)

                with st.beta_expander("Stopwords"):
                    st.success("Stop Words List")
                    stop_w = nt.TextExtractor(raw_text).extract_stopwords()
                    st.error(stop_w)

            with col2:
                with st.beta_expander("Processed text"):
                    st.success("Processed text")
                    processed_text = raw_text.lower()
                    processed_text = str(nt.TextFrame(raw_text).remove_stopwords())
                    processed_text = nfx.clean_text(processed_text, urls=True, numbers=True, puncts=True, stopwords=True, emails=True, phone_num=True, non_ascii=True, multiple_whitespaces=True, contractions=True)
                    processed_text = nfx.remove_shortwords(processed_text)
                    for ct in customText:
                        processed_text = nfx.clean_text(processed_text, custom_pattern=ct)
                    final_processed_text = processed_text
                    st.write(final_processed_text)

            st.write("")
            st.write("")
            st.info("Advanced Analysis")
            col3, col4 = st.beta_columns(2)

            with col3:
                with st.beta_expander("WordCloud"):
                    st.success("WordCloud")
                    plot_wordcloud(final_processed_text)

            with col4:
                with st.beta_expander("Tokens&Lemmas"):
                    st.write("T&L")
                    processed_text_mid = str(nt.TextFrame(raw_text).remove_stopwords())
                    processed_text_mid = str(nt.TextFrame(processed_text_mid).remove_puncts())
                    processed_text_fin = str(nt.TextFrame(processed_text_mid).remove_special_characters())
                    tandl = text_analyzer(processed_text_fin)
                    st.json(tandl)

    elif choice == "About":
        st.subheader("About")

        st.write("")
        st.write("")

        st.markdown("""
        ### By
        + *Abhay Chaskar*
        + *Shiva Saran*
        + *Shraddha Gadekar*
        + *Balaleshwar Raut*
        """)



if __name__ == '__main__':
    main()
